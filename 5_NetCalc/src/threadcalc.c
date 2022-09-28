#include "../include/equation.h"
#include "../include/threadpool.h"
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <inttypes.h>
#include <endian.h>
#include <linux/limits.h>
#include <getopt.h>
#include <pthread.h>

#define QUEUE_CAPACITY 50

threadpool_t *threadpool;
char unsolveddir[PATH_MAX] = {0};
char solveddir[PATH_MAX] = {0};
int finished = 0;

/**
 * @brief print usage statement
 * 
 */
void print_usage()
{
    printf("\n\nUsage: ./threadcalc <unsolved_directory> <solved_directory> (optional -n <threadcount>)\n\nRunning with thread count: 4\n\n");
}

/**
 * @brief parses files and prints according to filecalc format
 * as provided in the directions. Uses f_calc and s_calc to perform file
 * and mathematic operations
 * 
 * @param pathname filename to file to parse
 */
void parse_file(void *filename)
{
    char *p_filename = filename;
    if (NULL != filename)
    {
        struct header headerbuff;
        char upath[PATH_MAX] = {0};
        char spath[PATH_MAX] = {0};

        int u = sprintf(upath, "%s%s", unsolveddir, p_filename);
        int s = sprintf(spath, "%s%s", solveddir, p_filename);

        int ufd = open(upath, O_RDONLY | O_EXCL);
        int sfd = open(spath, O_RDWR | O_CREAT);
        int rv = fchmod(sfd, 0644);
        if (u != strlen(upath) || s != strlen(spath) || ufd == -1 || sfd == -1 || rv < 0)
        {
            if (ufd == -1)
            {
                printf("Could not open unsolved file! %s\n", upath);
            }
            if (sfd == -1)
            {
                printf("Could not open solved file! %s\n", upath);
            }
            if (rv < -1)
            {
                printf("Could not assign permission to file! %d\n", rv);
            }
        }
        else
        {
            if (read(ufd, &headerbuff, sizeof(headerbuff)) != sizeof(headerbuff))
            {
                printf("Malformed file. Due to header.\n");
            }
            else
            {
                headerbuff.flags = 1;
                write_header(sfd, &headerbuff);
                lseek(ufd, le32toh(headerbuff.offset), SEEK_SET);
                for (int i = 0; i < le64toh(headerbuff.numeq); i++)
                {
                    struct unsolved_equation unsolveq;
                    struct solved_equation solveq;
                    if (read(ufd, &unsolveq, sizeof(struct unsolved_equation)) != sizeof(unsolveq))
                    {
                        printf("Malformed file due to equation buffer\n");
                    }
                    else
                    {
                        if (operand_decider(le16toh(unsolveq.operatr)) == 1)
                        {
                            int64_t solution;
                            solveq.eqid = unsolveq.eqid;
                            solveq.type = 1;
                            if (signedcalc(le64toh(unsolveq.operand1), unsolveq.operatr, le64toh(unsolveq.operand2), &solution))
                            {
                                solveq.flags = 1;
                                solveq.solution = solution;
                            }
                            else
                            {
                                printf("\nUnsolved!!!\n");
                                solveq.flags = 0;
                            }

                            if (!write_equation(sfd, &solveq))
                            {
                                printf("\nWrite failure!\n");
                            }
                        }
                        else if (operand_decider(le16toh(unsolveq.operatr)) == 0)
                        {
                            uint64_t solution;
                            solveq.eqid = unsolveq.eqid;
                            solveq.type = 0;
                            if (unsignedcalc(le64toh(unsolveq.operand1), unsolveq.operatr, le64toh(unsolveq.operand2), &solution))
                            {
                                solveq.flags = 1;
                                solveq.solution = solution;
                            }
                            else
                            {
                                printf("\nUnsolved!!!\n");
                                solveq.flags = 0;
                            }

                            if (!write_equation(sfd, &solveq))
                            {
                                printf("\nWrite failure!\n");
                            }
                        }
                        else
                        {
                            printf("\nOperator error!\n");
                        }
                    }
                }
            }
        }
        free(filename);
        filename = NULL;
        close(ufd);
        close(sfd);
    }
}

/**
 * @brief Parse unsolved directory and pushes files into threadpool.
 * 
 * @param dirname unsolved dir name
 * @param sdirname solved dir name
 */
void parse_dir_dfs(char dirname[], char sdirname[])
{
    DIR *folder = opendir(dirname);
    if (folder == NULL)
    {
        return;
    }
    else
    {
        struct dirent *entry = readdir(folder);
        while (entry != NULL)
        {
            // Don't print CWD or parent
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                char *p_dname = calloc(1, strlen(entry->d_name) + 1);
                if (!p_dname)
                {
                    break;
                }
                strcpy(p_dname, entry->d_name);
                push_work(threadpool, (void *)p_dname);
            }
            entry = readdir(folder);
        }
    }
    closedir(folder);
    return;
}

/**
 * @brief Function to be passed to threads. Loops until all files
 * have been parsed and all work is done. Returns NULL when done
 * 
 */
void *thread_function(void *voidp)
{
    void *filename = pull_work(threadpool);
    while (!finished || NULL != filename)
    {
        if (NULL != filename)
        {
            parse_file(filename);
        }
        filename = pull_work(threadpool);
    }
    return NULL;
}

/**
 * @brief threadcalc parses unsolved directory full of binary
 * files in filecalc unsolved format, parses the individual 
 * binaries, and solves math problems while writing them to 
 * solved directory with the same file name and in filecalc solved 
 * format.
 * 
 * @param argc arg count
 * @param argv argv[1] = <path to unsolved directory>
 * argv[2] = <path to solved directory>
 * 
 * optional -n <threadcount>
 * 
 * @return int 
 */

int main(int argc, char *argv[])
{
    //Get thread count; defaulting to 4
    int threadcount = 4;
    int getcount = getopt(argc, argv, "n:");
    switch (getcount)
    {
    case 'n':
        threadcount = atoi(optarg);
        break;
    default:
        print_usage();
        break;
    }

    //initialize threapool object
    threadpool = threadpool_init(threadcount, QUEUE_CAPACITY, thread_function, NULL);

    //if directories are supplied in arguments, parse unsolved directory
    if (NULL != argv[1] && NULL != argv[2] && NULL != threadpool && threadcount > 0)
    {
        int u = sprintf(unsolveddir, "%s/", argv[1]);
        int s = sprintf(solveddir, "%s/", argv[2]);
        if (strlen(unsolveddir) == u && strlen(solveddir) == s)
        {
            parse_dir_dfs(argv[1], argv[2]);
        }
        finished = 1;
    }

    //threadpool cleanup
    terminate_threadpool(threadpool);
    return 0;
}