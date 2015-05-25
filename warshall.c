#include<stdio.h>
#include<stdlib.h>
int p[10][10],n;

void warshall()
{
	int i,j,k;

	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{ 
				if(p[i][j]==0 && (p[i][k]==1 && p[k][j]==1))
				{
					p[i][j]=1;
				}
			}
		}
	}

}

void main()
{
	int a[10][10],i,j;

	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{ 
				scanf("%d",&a[i][j]);
			}
		}
	printf("1\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			{ 
				p[i][j]=a[i][j];
			}
		}
		printf("2\n");

		printf("The adjacency matrix entered by you is : \n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{ 
				printf("%d\t",a[i][j]);
			}
			printf("\n");
		}
		warshall();
		printf("The path matrix is : \n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{ 
				printf("%d\t",p[i][j]);

			}
			printf("\n");
		}

}
