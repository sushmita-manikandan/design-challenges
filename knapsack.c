#include<stdio.h>
#include<stdlib.h>

int n,m;
int w[10];
int p[10];

void knapsack()
{
	int i,j,v[10][10];
	int x[10];

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				v[i][j]=0;
			else if(j<w[i])
				v[i][j]=v[i-1][j];
			else
				v[i][j]=v[i-1][j]>(v[i-1][j-w[i]]+p[i])?v[i-1][j]:(v[i-1][j-w[i]]+p[i]);
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d\t",v[i][j]);
		}
		printf("\n");
	}
	printf("The optimal solution is : %d\n",v[n][m]);
	i=n;
	j=m;
	while(i>0 && j>0)
	{
		if(v[i][j]!=v[i-1][j])
		{
			x[i]=1;
			j=j-w[i];
		}
		i=i-1;
	}
	printf("The itmes selcted are\n");

	for(i=1;i<=n;i++)
	{
		if(x[i]==1)
			printf("%d  ",i);
	}
	printf("\n");
}

void main()
{	
	int i;
	printf("Enter the number of items\n");
	scanf("%d",&n);
	printf("Enter the weights and profits\n");
	for(i=1;i<=n;i++)
		scanf("%d%d",&w[i],&p[i]);
	
	printf("Enter the maximum capacity\n");
	scanf("%d",&m);
	knapsack();
}
