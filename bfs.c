#include<stdio.h>
#include<stdlib.h>

int c[10][10],n,vis[10];

void bfs(int src)
{
	int i,j,f=0,r=0,q[10];
	
	for(i=1;i<=n;i++)
		vis[i]=0;
	
	q[++r]=src;
	++f;
	while(f<=r)
	{
		i=q[f++];
		for(j=1;j<=n;j++)
		{
			if(c[i][j]==1 && vis[j]==0)
			{
				q[++r]=j;
				vis[j]=1;
			}
		}
	}
}
void main()
{
	int i,src,j;
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
	printf("enter the source\n");
	scanf("%d",&src);

	bfs(src);
	
	for(i=1;i<=n;i++)
	{
		if(i!=src)
		{
			if(vis[i]==1)
				printf("%d is reachable from source\n",i);
			else
				printf("%d is not reachable from source\n",i);
		}
	}

}		
