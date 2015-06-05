#include<stdio.h>
#include<stdlib.h>

int vis[10]={0};
void main()
{
	int i,j,u,v,a,b,min,minc=0,ne=0;
	int n, c[10][10];

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
	vis[1]=1;
	while(ne!=(n-1))
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(c[i][j]<min && c[i][j]!=0)
				{
					min=c[i][j];
					a=u=i;
					b=v=j;
				}	
			}
		}
		if(vis[u]==0 || vis[v]==0)
		{
			printf("edge %d (%d-->%d), cost = %d\n",++ne,a,b,min);
			minc+=min;
			vis[b]=1;
		}
		c[a][b]=c[b][a]=999;
	}
	printf("The minmum cost incurred is %d\n",minc);
}
