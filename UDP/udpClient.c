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
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in addr;
	int s=sizeof(struct sockaddr_in);
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=INADDR_ANY;
	addr.sin_port=3008;
	connect(sockfd,(struct sockaddr *)&addr,sizeof(addr));
	do{
		printf("Sending message to server\n");
		scanf("%s",buff);
		sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&addr,s);
		recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&addr,&s);
		printf("Received from server %s\n",buff);
	}while(strcmp(buff,"stop")!=0);
	close(sockfd);
}
