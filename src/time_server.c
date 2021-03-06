// Last Update:2018-01-02 10:12:41
/**
 * @file time_server.c
 * @brief 
 * @author luxueqian
 * @version 0.1.00
 * @date 2017-12-27
 */
#include "common.h"
#include "merror.h"
#include <time.h>

int main(int argc, char *argv[])
{
    int listenfd, connfd;
    char buff[MAXLINE+1] = {0};
    struct sockaddr_in servaddr;
    time_t ticks;
    if (argc != 3)
    {
        err_quit("usage: %s <IPaddress> <Port>", argv[0]);
    }

    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (bind(listenfd, (SA*)&servaddr, sizeof(servaddr)) < 0)
        err_sys("bind error");

    if (listen(listenfd, LISTENQ) < 0)
        err_sys("listen error");
    for(;;)
    {
        struct sockaddr_in client;
        int len = sizeof(client);
        connfd = accept(listenfd, (SA*)NULL, NULL);
        if(!getpeername(connfd, (SA*)&client, &len))
        { 
            printf("connected from %s:%d.\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        }
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(connfd, buff, strlen(buff));
        close(connfd);
    }

    return 0;
}
