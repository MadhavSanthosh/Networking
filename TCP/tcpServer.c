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
	struct sockaddr_in addr1,addr2;
	addr1.sin_family=AF_INET;
	addr1.sin_addr.s_addr=INADDR_ANY;
	addr1.sin_port=3008;
	int s=sizeof(struct sockaddr_in);
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bind(sockfd,(struct sockaddr *)&addr1,sizeof(addr1));
	listen(sockfd,5);
	newsocket=accept(sockfd,(struct sockaddr *)&addr2,(&s));
	do{	
		printf("Connection established\nRecieving message from client\n");
		recv(newsocket,buff,sizeof(buff),0);
		printf("%s\n",buff);
		printf("Enter message\n");
		scanf("%s",buff);
		send(newsocket,buff,sizeof(buff),0);
	}while(strcmp(buff,"stop")!=0);
	close(newsocket);
	close(sockfd);
}