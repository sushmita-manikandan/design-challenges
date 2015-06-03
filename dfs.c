#include<stdio.h>
#include<stdlib.h>

int c[10][10],n,vis[10];

void dfs(int src)
{
	int i;
	vis[src]=1;
	for(i=1;i<=n;i++)
	{
		if(c[src][i]!=0 && vis[i]==0)
		{
			dfs(i);
		}
	}
}

void main()
{
	int i,j;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the cost matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	dfs(1);
	
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			printf("Graph is disconnected\n");
			exit(0);
		}
	}
	printf("Graph is connected\n");
}
