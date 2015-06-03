#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,cnt,x[10];

int place(int x[],int k)
{
	int i;
	for(i=1;i<k;i++)
	{
		if((x[i]==x[k]) || abs(i-k)==abs(x[i]-x[k]))
		return 0;
	}
	return 1;
}
void print_sol()
{
	int i,j;
	char c[10][10];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			c[i][j]='X';
		}
	}
	for(i=1;i<=n;i++)
	{
		if(x[i]!=0)
			c[i][x[i]]='Q';
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%c\t",c[i][j]);
		}
		printf("\n");

	}
}
	
void nqueens()
{
	int i,k;
	k=1;
	x[k]=0;
	while(k!=0)
	{
		x[k]+=1;
		while(x[k]<=n && (!place(x,k)))
			x[k]+=1;
		if(x[k]<=n)
		{
			if(k==n)
			{
				cnt++;
				printf("Solution %d is\n",cnt);
				print_sol();
			}
			else
			{
				k++;
				x[k]=0;
			}
		}
		else
		{
			x[k]=0;
			k--;
		}
	}
}

void main()
{
	printf("Enter the size of chessboard\n");
	scanf("%d",&n);
	nqueens();
}

