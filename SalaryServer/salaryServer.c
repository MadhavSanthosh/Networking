#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
void main()
{	printf("Server Side\n");
	int buff[5];
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
		printf("Connection established\nReceiving message from client\n");
		recv(newsocket,buff,sizeof(buff),0);
		printf("Basic salary=%d\n",buff[0]);
		printf("HRA=%d\n",buff[1]);
		printf("DA=%d\n",buff[2]);
		printf("PT=%d\n",buff[3]);
		printf("EPF=%d\n",buff[4]);
		int netsal=buff[0]+buff[1]+buff[2]-buff[3]-buff[4];
		buff[0]=netsal;
		send(newsocket,buff,sizeof(buff),0);
	}while(buff[0]!=0);
	close(newsocket);
	close(sockfd);
}