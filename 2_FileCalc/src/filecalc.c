#include "../../0_Common/include/common.h"

/**
 * @brief holds header information for files
 * as specified in ../references/filecalc.pdf
 * 
 */

struct header
{
    uint32_t magic;
    uint64_t fileid;
    uint64_t numeq;
    uint8_t flags;
    uint32_t offset;
    uint16_t optheaders;
}__attribute__((packed));

/**
 * @brief holds equation format for unsolved eqs
 * as specified in ../references/filecalc.pdf
 * 
 */
struct unsolved_equation
{
    uint32_t eqid;
    uint8_t flags;
    uint64_t operand1;
    uint8_t operator;
    uint64_t operand2;
    char padding[10];
}__attribute__((packed));


/**
 * @brief holds solved equations in the format 
 * specified in ../references/filecalc.pdf
 * 
 */
struct solved_equation
{
    uint32_t eqid;
    uint8_t flags;
    uint8_t type;
    uint64_t solution;
}__attribute__((packed));

/**
 * @brief writes header information to solved file
 * 
 * @param fd - file descriptor for solved file to write to
 * @param hdr - pointer to header struct
 * @return int returns 1 if successful, 0 on error
 */
int write_header(int fd, struct header *hdr)
{
    int success = 0;
    if (write(fd, hdr, sizeof(struct header)) == sizeof(struct header))
    {
        success = 1;
    }
    return success;
}
/**
 * @brief writes equation data to solved file
 * 
 * @param fd - file descriptor for solved file to write to
 * @param sequ - pointer to solved equation struct
 * @return int returns 1 if successful, 0 on error
 */
int write_equation(int fd, struct solved_equation *sequ)
{
    int success = 0;
    if (write(fd, sequ, sizeof(struct solved_equation)) == sizeof(struct solved_equation))
    {
        success = 1;
    }
    return success;
}

/**
 * @brief parses file for equation information to conduct math
 * 
 * @param upath - path to unsolved file
 * @param spath - path to solved file
 */
void parse_file(char upath[], char spath[])
{
    struct header headerbuff;
    int ufd = open(upath, O_RDONLY | O_EXCL);
    int sfd = open(spath, O_RDWR | O_CREAT);
    int rv = fchmod(sfd, 0644);
    if (ufd == -1 || sfd == -1 || rv < 0)
    {
        if (ufd == -1)
        {
            printf("Could not open unsolved file! %s\n", upath);
        }
        if (sfd == -1)
        {
            printf("Could not open solved file! %s\n", spath);
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
                    if (signage_decider(le16toh(unsolveq.operator)) == 1)
                    {
                        int64_t solution;
                        solveq.eqid = unsolveq.eqid;
                        solveq.type = 1;
                        if (signedcalc(le64toh(unsolveq.operand1), unsolveq.operator, le64toh(unsolveq.operand2), &solution))
                        {
                            solveq.flags = 1;
                            solveq.solution = solution;
                        }
                        else 
                        {
                            printf("\nUnsolved!!!\n");
                            solveq.flags = 0;
                        }

                        if(!write_equation(sfd, &solveq))
                        {
                            printf("\nWrite failure!\n");
                        }

                    }
                    else if (signage_decider(le16toh(unsolveq.operator)) == 0)
                    {
                        uint64_t solution;
                        solveq.eqid = unsolveq.eqid;
                        solveq.type = 0;
                        if (unsignedcalc(le64toh(unsolveq.operand1), unsolveq.operator, le64toh(unsolveq.operand2), &solution))
                        {
                            solveq.flags = 1;
                            solveq.solution = solution;
                        }
                        else 
                        {
                            printf("\nUnsolved!!!\n");
                            solveq.flags = 0;
                        }

                        if(!write_equation(sfd, &solveq))
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
        close(ufd);
        close(sfd);
    }
}

/**
 * @brief parses directory for files to parse. calls parse file
 * 
 * @param dirname - path to unsolved directory
 * @param sdirname - path to solved directory
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
                char upath[PATH_MAX] = {0};
                char spath[PATH_MAX] = {0};
                strcat(spath, sdirname);
                strcat(upath, dirname);
                strcat(upath, "/");
                strcat(spath, "/");
                strcat(upath, entry->d_name);
                strcat(spath, entry->d_name);

                parse_file(upath, spath); //WARNING: assumed that directory contains only files
            }
            entry = readdir(folder);
        }
    }
    closedir(folder);
    return;
}

int main(int argc, char *argv[])
{
    parse_dir_dfs(argv[1], argv[2]);
    return 0;
}