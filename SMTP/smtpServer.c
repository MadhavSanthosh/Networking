#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
void main()
{	printf("Server Side\n");
	char toadd[50],fromadd[50],head[50],body[50];
	int sockfd,newsocket;int x=1;
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
		recv(newsocket,toadd,sizeof(toadd),0);
		recv(newsocket,fromadd,sizeof(fromadd),0);
		recv(newsocket,head,sizeof(head),0);
		recv(newsocket,body,sizeof(body),0);
		printf("To address:%s",toadd);
		printf("From address:%s",fromadd);
		printf("Header:%s",head);
		printf("Body:%s",body);
		char toDomain[50],fromDomain[50];
		int i=0,j=0;
		while(toadd[i]!='@')
			i++;
		i++;
		while(toadd[i]!='\0')
		{	toDomain[j]=toadd[i];
			i++;j++;
		}
		printf("To Domain:%s",toDomain);
		i=0,j=0;
		while(fromadd[i]!='@')
			i++;
		i++;
		while(fromadd[i]!='\0')
		{	fromDomain[j]=fromadd[i];
			i++;j++;
		}
		printf("From Domain:%s",fromDomain);
	}while(x==1);
	close(newsocket);
	close(sockfd);
}