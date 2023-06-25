#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
void main()
{	printf("Client Side\n");
	char toadd[50],fromadd[50],head[50],body[50];
	int sockfd;int x=1;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr1,addr2;
	addr2.sin_family=AF_INET;
	addr2.sin_addr.s_addr=INADDR_ANY;
	addr2.sin_port=3008;
	connect(sockfd,(struct sockaddr *)&addr2,sizeof(addr2));
	do{
		printf("Enter to address\n");
		fgets(toadd,50,stdin);
		printf("Enter from address\n");
		fgets(fromadd,50,stdin);
		printf("Enter header part\n");
		fgets(head,50,stdin);
		printf("Enter body part\n");
		fgets(body,50,stdin);
		send(sockfd,toadd,sizeof(toadd),0);
		send(sockfd,fromadd,sizeof(fromadd),0);
		send(sockfd,head,sizeof(head),0);
		send(sockfd,body,sizeof(body),0);
	}while(x==1);
	close(sockfd);
}