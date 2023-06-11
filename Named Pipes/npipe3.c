#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{	printf("Process 3\n");
	int a[3];
	char *fifo2="fifo2.txt";
	mkfifo(fifo2,0666);
	int id=open(fifo2,O_RDONLY);
	read(id,a,sizeof(a));		
	printf("Number of characters is %d\n",a[0]);
	printf("Number of words is %d\n",a[1]);
	printf("Number of sentence %d\n",a[2]);
	close(id);
}