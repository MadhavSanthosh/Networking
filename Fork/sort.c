#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{	printf("Enter number of elements\n");
	int n;
	scanf("%d",&n);
	int a[n];
	printf("Enter %d numbers\n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	pid_t pid =fork();
	if (pid<0)
	{	printf("ERROR");
	}
	else if (pid==0)
	{	printf("Child Process\n");
		printf("Descending order is ");
		for(int i=0;i<n-1;i++)
		{	for(int j=0;j<n-i-1;j++)
			{	if(a[j]<a[j+1])
				{	int t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	else
	{	printf("Parent Process\n");
		printf("Ascending order is ");
		for(int i=0;i<n-1;i++)
		{	for(int j=0;j<n-i-1;j++)
			{	if(a[j]>a[j+1])
				{	int t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}	
}