#include <stdio.h>
#include <stdlib.h>
void input(int a[],int fsize)
{	for(int i=0;i<fsize;i++)
	{	printf("Enter value for Frame %d\n",i+1);
		scanf("%d",&a[i]);
	}
}
void sRep(int a[],int wsize,int fsize)
{	int nt=0,k=0;
	int left[50]={-1};
	for(int i=0;i<fsize;i++)
	{	int flag=rand()%2;
		if(flag)
		{	printf("Frame %d with value %d has been acknowledged!!\n",i+1,a[i]);
			nt++;
		}
		else
		{	printf("Frame %d with value %d has not been acknowledged!!\n",i+1,a[i]);
			left[k++]=i;
			nt++;
		}
		if(i%wsize==0)
		{	for(int x=0;x<k;x++)
			{	printf("Frame %d with value %d has been retransmitted!!\n",left[x]+1,a[left[x]]);
				nt++;
				printf("Frame %d with value %d has been acknowledged on second attempt!!\n",left[x]+1,a[left[x]]);
			}
			k=0;
		}
	}
	for(int i=0;i<k;i++)
	{	printf("Frame %d with value %d has been retransmitted!\n",left[i]+1,a[left[i]]);
		nt++;
		printf("Frame %d with value %d has been acknowledged on second attempt!!\n",left[i]+1,a[left[i]]);
	}
	printf("Total transmissions=%d\n",nt);
}
void main()
{	int frames[50],wsize,fsize;
	printf("Enter window size\n");
	scanf("%d",&wsize);
	printf("Enter number of frames\n");
	scanf("%d",&fsize);
	input(frames,fsize);
	sRep(frames,wsize,fsize);
}