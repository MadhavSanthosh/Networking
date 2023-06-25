#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
void main()
{	printf("Client Side\n");
	int buff[5];
	int sockfd;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr1,addr2;
	addr2.sin_family=AF_INET;
	addr2.sin_addr.s_addr=INADDR_ANY;
	addr2.sin_port=3008;
	connect(sockfd,(struct sockaddr *)&addr2,sizeof(addr2));
	do{
		printf("Sending message to server\n");
		printf("Enter basic salary ");
		scanf("%d",&buff[0]);
		printf("Enter HRA ");
		scanf("%d",&buff[1]);
		printf("Enter DA ");
		scanf("%d",&buff[2]);
		printf("Enter PT ");
		scanf("%d",&buff[3]);
		printf("Enter EPF ");
		scanf("%d",&buff[4]);
		send(sockfd,buff,sizeof(buff),0);
		recv(sockfd,buff,sizeof(buff),0);
		printf("Received from server\nNet salary=%d\n",buff[0]);
	}while(buff[0]!=0);
	close(sockfd);
}