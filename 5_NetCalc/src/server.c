#include "../include/common.h"
#include "../../4_ThreadCalc/include/threadpool.h"
#include "../../4_ThreadCalc/include/equation.h"
#include "../../3_DataStructures1/include/queue.h"
#include <linux/limits.h>

int handle_parsing(int connfd)
{
}

int main(int argc, void **args)
{
    int listenfd, connfd, n, port;
    struct sockaddr_in servaddr;
    port = 5555;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Failed to create socket!\n");
        exit(0);
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if ((bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) < 0)
    {
        printf("Failed to bind socket!\n");
        exit(0);
    }

    if ((listen(listenfd, 10)) < 0)
    {
        printf("Failed to listen!\n");
        exit(0);
    }

    for (;;)
    {
        char buffer[1024];
        printf("Waiting for connection on port %d...\n", port);
        fflush(stdout);
        connfd = accept(listenfd, NULL, NULL);
        printf("[CONNECTED]\n");
        snprintf(buffer, sizeof(buffer), "You have been connected!\n");
        send(connfd, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
    ///////////////////////////////////////

        int n, filenameLen;
        char recvline[1024] = {'\0'};
        n = recv(connfd, recvline, 1024, 0);
        filenameLen = atoi(recvline);
        printf("Filenamelen: %d\n", filenameLen);

        memset(recvline, '\0', sizeof(recvline));
        n = recv(connfd, recvline, 1024, 0);
        char path[PATH_MAX] = {'\0'};
        printf("Recvline: %s\n", recvline);
        snprintf(path, PATH_MAX, "/home/jeremiah/Documents/calcproject/5_NetCalc/Test2/%s", recvline);
        printf("Path: %s\n", path);
        memset(recvline, '\0', sizeof(recvline));
        FILE *fp = fopen(path, "w");
        n = recv(connfd, recvline, sizeof(struct header), 0);
        int byteswritten = 0;
        for (int i = 0; i < n; i++)
        {
            printf("%x", recvline[i]);
            byteswritten += fprintf(fp, "%c", recvline[i]);
        }
        printf("\nByteswritten: %d\n", byteswritten);
        fclose(fp);

    //////////////////////////////////////
        snprintf(buffer, sizeof(buffer), "You have been disconnected!\n");
        send(connfd, buffer, strlen(buffer), 0);
        close(connfd);
    }
}