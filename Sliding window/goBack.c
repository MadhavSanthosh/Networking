#include <stdio.h>
#include <stdlib.h>
void input(int a[],int fsize)
{	for(int i=0;i<fsize;i++)
	{	printf("Enter value for Frame %d\n",i+1);
		scanf("%d",&a[i]);
	}
}
void gBack(int a[],int wsize,int fsize)
{	int nt=0,k=0;
	int left[50]={-1};
	for(int i=0;i<fsize;i++)
	{	int flag=rand()%2;
		if(flag)
		{	printf("Frame %d with value %d has been acknowledged\n",i+1,a[i]);
			nt++;
		}
		else
		{	printf("Frame %d with value %d has not been acknowledged\n",i+1,a[i]);
			left[k++]=i;
			nt++;	
		}
		if(i%wsize==0 && i>0)
		{	for(int x=left[0];x<=i;x++)
			{	printf("Frame %d with value %d has been retransmitted\n",x+1,a[x]);
				nt++;
				printf("Frame %d with value %d has been acknowledged on second attempt\n",x+1,a[x]);
			}
			k=0;left[0]=-1;
		}
	}
	int i=left[0];
	while(i<fsize && i>=0)
	{	printf("Frame %d with value %d has been retransmitted\n",i+1,a[i]);
		nt++;
		printf("Frame %d with value %d has been acknowledged on second attempt\n",i+1,a[i]);
		i++;
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
	gBack(frames,wsize,fsize);
}