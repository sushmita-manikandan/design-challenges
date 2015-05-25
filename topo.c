#include<stdio.h>
#include<stdlib.h>

int n,a[10][10];
void topo()
{
	int sol[10],solncnt=1,u,i,j,k,s[10],top=-1,sum=0,indeg[10];
	for(j=1;j<=n;j++)
	{
		sum=0;
		for(i=1;i<=n;i++)
		{
			sum=sum+a[i][j];
		}
		indeg[j]=sum;
	}
	for(j=1;j<=n;j++)
	{
		if(indeg[j]==0)
		{
			s[++top]=j;
		}
	}
	while(top!=-1)
	{
	u=s[top--];
	sol[solncnt++]=u;

		for(j=1;j<=n;j++)
		{
			if(a[u][j]==1)
			{
				indeg[j]--;
				if(indeg[j]==0)
				{
					s[++top]=j;
				}
			}
		}
	}
	for(k=1;k<solncnt;k++)
		printf("%d\t",sol[k]);
	
}

void main()
{
	int i,j;

	printf("Enter the number of elements\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	topo();
}
