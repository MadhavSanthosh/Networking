#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
void main()
{	printf("Client Side\n");
	char buff[50];
	int sockfd;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr1,addr2;
	addr2.sin_family=AF_INET;
	addr2.sin_addr.s_addr=INADDR_ANY;
	addr2.sin_port=3008;
	connect(sockfd,(struct sockaddr *)&addr2,sizeof(addr2));
	do{
		printf("Sending name of file to server\n");
		scanf("%s",buff);
		send(sockfd,buff,sizeof(buff),0);
		recv(sockfd,buff,sizeof(buff),0);
		printf("Received from server %s",buff);
	}while(strcmp(buff,"stop")!=0);
	close(sockfd);
}