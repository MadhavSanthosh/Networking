#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{	char *fifo1="fifo1.txt";
	mkfifo(fifo1,0666);
	int fd; 
	fd=open(fifo1,O_WRONLY);
	printf("Process 1\n");
	char sen[100];
	printf("Enter sentence\n");
	fgets(sen,100,stdin);
	write(fd,sen,sizeof(sen));
	close(fd);
}  