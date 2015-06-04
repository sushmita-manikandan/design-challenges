#include<stdio.h>
#include<stdlib.h>

int d,w[10],cnt;
int x[10];

void subset(int weightsofar,int k,int totremsum)
{
	int i;
	x[k]=1;
	if(weightsofar+w[k]==d)
	{
		printf("Solution %d\n",++cnt);
		for(i=0;i<=k;i++)
		{
			if(x[i]==1)
			printf("%d\t",w[i]);
		}
		printf("\n");
	}
	else if(weightsofar+w[k]+w[k+1]<=d)
		subset(weightsofar+w[k],k+1,totremsum-w[k]);

	if(weightsofar+totremsum-w[k]>=d && weightsofar+w[k+1]<=d)
	{
		x[k]=0;
		subset(weightsofar,k+1,totremsum-w[k]);
	}
}

void main()
{
	int i,n,sum=0;
	printf("Enter the number of items in the set\n");
	scanf("%d",&n);
	printf("Enter rhe items\n");
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("Enter the desired sum\n");
	scanf("%d",&d);

	for(i=0;i<n;i++)
		sum+=w[i];
	if(sum<d)
	{
		printf("No solution exists\n");
		exit(0);
	}
	cnt=0;
	subset(0,0,sum);
}
