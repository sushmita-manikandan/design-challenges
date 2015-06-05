#include<stdio.h>
#include<stdlib.h>

int c[10][10],n;

void kruskal()
{
	int ne=0,minc=0,min,i,j,u,v,a,b,p[10];
	
	for(i=1;i<=n;i++)
		p[i]=0;

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
		
		while(p[u]!=0)
		u=p[u];
		while(p[v]!=0)
		v=p[v];
	
		if(u!=v)
		{
			printf("Edge %d (%d-->%d),cost= %d\n",++ne,a,b,min);
			minc+=min;
			p[v]=u;
		}
		c[a][b]=c[b][a]=999;
	}
	printf("The minimum cost is %d\n",minc);

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

	kruskal();
}
