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
    svaddr.sin_port = htons(PORT_NUM);
    inet_pton(AF_INET,"101.132.40.140",&svaddr.sin_addr.s_addr);

    if(sfd == -1 )
        perror("sfd");

    for(int i=0;i<4;i++)
    {
        char inputbuf[BUF_SIZE];
        printf("please input ");
        scanf("%s",&inputbuf);
        int len = strlen(inputbuf);
        int msglen = sendto(sfd,inputbuf ,len,0,(struct sockaddr *) &svaddr, sizeof(struct sockaddr_in));
        if(msglen != len)
            perror("send");
        char recvbuf[BUF_SIZE];
        int nums = recvfrom(sfd,recvbuf,BUF_SIZE,0, NULL, NULL);
        printf("%s\n", recvbuf);
    }
}