//
// Created by yurunyang on 18-11-22.
//

#include <memory.h>
#include <stdio.h>
#include "i6d_ucase.h"

int main()
{
    struct sockaddr_in svaddr;
    int sfd,j;
    sfd = socket(AF_INET,SOCK_DGRAM, 0);
    memset(&svaddr, 0, sizeof(struct sockaddr));

    svaddr.sin_family = AF_INET;
    svaddr.sin_port = 9999;
    inet_pton(AF_INET,"101.132.40.140",&svaddr.sin_addr.s_addr);

    if(sfd == -1 )
        perror("sfd");

    for(int i=0;i<4;i++)
    {
        char *inputbuf;
        scanf("%s",inputbuf);
        sendto(sfd,inputbuf,strlen(inputbuf),0,&svaddr, sizeof(svaddr));

        char *recvbuf;
        int nums = recvfrom(sfd,recvbuf,BUF_SIZE,0, NULL, NULL);
        printf("%s\n", recvbuf);
    }
}