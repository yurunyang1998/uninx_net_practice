#include <memory.h>
#include <error.h>
#include <printf.h>
#include <stdlib.h>
#include "stdio.h"
#include "i6d_ucase.h"

int main() {
    struct sockaddr_in svaddr, claddr;
    int sfd, j;
    ssize_t numBytes;
    socklen_t len;
    char buf[BUF_SIZE];
    char claddrStr[INET_ADDRSTRLEN];
    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sfd == -1)
        perror("socket");

    memset(&svaddr, 0, sizeof(struct sockaddr_in6));
    svaddr.sin_family = AF_INET;
    svaddr.sin_addr.s_addr =  INADDR_ANY;
    svaddr.sin_port = htons(PORT_NUM);

    if (bind(sfd,  ( struct sockaddr_in *) &svaddr, sizeof(svaddr) )== -1)
        perror("bind");
    else
        printf("bind succeed \n");

    for (;;) {
        len = sizeof(struct sockaddr_in);
        numBytes = recvfrom(sfd, buf, BUF_SIZE, 0, &claddr, len);
        if (numBytes == -1)
            perror("recv");
        if (inet_ntop(AF_INET, &claddr.sin_addr, claddrStr, INET_ADDRSTRLEN) == NULL)
            printf("can not find client address");
        else
            printf("the client address is %d", claddrStr);

        if (sendto(sfd, buf, numBytes, 0, &claddr, len) == -1)
            perror("sendto");
    }
}





	
