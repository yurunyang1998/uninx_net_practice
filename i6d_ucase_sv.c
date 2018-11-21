#include "i6d_ucase.h"
int main()
{
	struct sockaddr_in svaddr,claddr;
 	int sfd,j;
	ssize_t numBytes;
	socklen_t len;
	char buf[BUF_SIZE];
	char claddrStr[INET6_ADDRSTRLEN];
	sfd = socket(AF_INT6,SOCK_DGRAM,0);
	if(sfd == -1)
		errExit("socket");
	
	memset(&svaddr,0,sizeof(struct sockaddr_in6));
	svaddr.sin_family = AF_INT6;
	svaddr.sin_addr = in6addr_any;
	svaddr.sin_port = htons(PORT_NUM);
	
	if(bind(sfd,&svaddr,sizeof(struct sockaddr_in) == -1 )
		error("bind");
	
	for(;;)
	{
		len =  sizeof(struct sockaddr_in);
		numBytes = recvfrom(sfd,buf,BUF_SIZE,0,&claddr,len);
		if(numBytes == -1 )
			error("recefrom");
		if(inet_ntop(AF_INET,claddr.sin_addr, claddrStr, INT_ADDRSTRLEN) == NULL ) 
		printf("can not find client address");
		else
		printf("the client address is %d",claddrStr);
		
		if(sendto(sfd, buf, numBytes, 0 , &claddr, len) == -1 )
			errExit("sendto");
	}





	
