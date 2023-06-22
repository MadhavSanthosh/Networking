#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
void main()
{	printf("Server Side\n");
	char buff[50],url[50],ip[50];
	FILE *fp;
	int sockfd,newsocket;
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=INADDR_ANY;
	addr.sin_port=3008;
	int s=sizeof(struct sockaddr_in);
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bind(sockfd,(struct sockaddr *)&addr,sizeof(addr));
	printf("Connection established\n");
	do{	printf("Receiving URL from client\n");
		recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&addr,&s);
		printf("%s\n",buff);
		if(strcmp(buff,"stop")!=0)
		{
		fp=fopen("dnstest","r");
		fscanf(fp,"%s\t%s",url,ip);
		while(strcmp(url,buff)!=0)
		{	fscanf(fp,"%s\t%s",url,ip);
		}
		strcpy(buff,ip);
		fclose(fp);
		}
		sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&addr,s);
	}while(strcmp(buff,"stop")!=0);
	close(sockfd);
}