#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
void main()
{	printf("Server Side\n");
	char buff[50];
	int sockfd,newsocket;
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=INADDR_ANY;
	addr.sin_port=3008;
	int s=sizeof(struct sockaddr_in);
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bind(sockfd,(struct sockaddr *)&addr,sizeof(addr));
	do{	printf("Connection established\nRecieving message from client\n");
		recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&addr,&s);
		printf("%s",buff);
		printf("Enter message\n");
		scanf("%s",buff);
		sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&addr,s);
	}while(strcmp(buff,"stop")!=0);
	close(sockfd);
}