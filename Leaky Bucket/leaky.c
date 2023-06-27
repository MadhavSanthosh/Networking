#include <stdio.h>
void main()
{	int n,size,rate,psize;
	int store=0;
	printf("Enter number of packets\n");
	scanf("%d",&n);
	printf("Enter size of bucket\n");
	scanf("%d",&size);
	printf("Enter output rate\n");
	scanf("%d",&rate);
	while(n!=0)
	{	printf("Remaining capacity=%d\n",size-store);
		printf("Enter size of packet\n");
		scanf("%d",&psize);
		if(psize<=size-store){
			printf("Packet accepted\n");
			store+=psize;
		}
		else{
			printf("Packet Rejected\n");
		}
		store-=rate;
		if(store<0)
			store=0;
		n--;
	}
}