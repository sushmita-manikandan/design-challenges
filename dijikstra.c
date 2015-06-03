#include<stdio.h>
#include<stdlib.h>

int n,a[10][10],d[10],p[10],s[10];

void optimal(int src,int dest)
{
	int i,j,min,v,u;

	for(i=1;i<=n;i++)
	{
		s[i]=0;
		d[i]=a[src][i];
		p[i]=src;
	}
	s[src]=1;
	
	for(i=1;i<=n;i++)
	{
		min=9999;
		u=-1;
		for(j=1;j<=n;j++)
		{
			if(s[j]==0)
			{
				if(d[j]<min)
				{
					min=d[j];
					u=j;
				}
			}
		}
	}
	if(u==-1) return;
	s[u]=1;
	if(u==dest) return;

	for(v=1;v<=n;v++)
	{
		if(s[v]==0 && (d[u]+a[u][v])<d[v])
		{
			d[v]=d[u]+a[u][v];
			p[v]=u;
		}
	}
	
}					

void print_path()
{
	int i,dest,src;
	
	printf("Enter the source\n");
	scanf("%d",&src);
	
	for(dest=2;dest<=n;dest++)
	{	optimal(src,dest);
		if(d[dest]==9999)
		printf("No path\n");
		else
		{
			i=dest;
			while(i!=src)
			{
				printf("%d <--- ",i);
				i=p[i];
			}
			printf("%d\n",src);
		}
		printf("Cost = %d \n", d[dest]);
	}	
}


void main()
{
	int i,j;

	printf("Enter the  number of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	print_path();
}
