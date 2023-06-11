#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{	printf("Process 2\n");
	char *fifo1="fifo1.txt";
	char *fifo2="fifo2.txt";
	mkfifo(fifo1,0666);
	mkfifo(fifo2,0666);
	int fd,id; 
	fd=open(fifo1,O_RDONLY);
	id=open(fifo2,O_WRONLY);
	char a[100];
	read(fd,a,sizeof(a));	
	printf("%s",a);
	int ch=0,wd=0,sn=0;
	int i=0;
	while(a[i]!='\0')
	{	if(a[i]==' '||a[i]=='.')
			wd++;
		if(a[i]=='.'||a[i]=='!'||a[i]=='?')
			sn++;
		i++;
	}
	ch=i-1;
	int b[3];
	b[0]=ch;b[1]=wd;b[2]=sn; 
	write(id,b,sizeof(b));
	close(fd);
	close(id);
}
