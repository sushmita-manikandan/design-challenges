#include<stdio.h>
#include<stdlib.h>

int a[10][10],n,vis1[10],vis2[10],cost;
float approxcost,exactcost,error;

void input()
{
	int i,j;
	printf("Enter the total number of cities\n");
	scanf("%d",&n);
	printf("Enter the cost matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		vis1[i]=0;
	}
	
}

void mincost1(int city)
{
	int ncity;

	vis1[city]=1;
	printf("%d --> ",city);
	ncity=least1(city);
	
	if(ncity==9999)
	{
		ncity=1;
		printf("%d ",ncity);
		cost=cost+a[city][ncity];
		return;
	}
	mincost1(ncity);
}

int least1(int c)
{
	int i,nc=9999,min=9999;

	for(i=1;i<=n;i++)
	{
		if(a[c][i]!=0 && vis1[i]==0)
		{
			if(a[c][i]<min)
			{
				min=a[c][i];
				nc=i;
			}
		}
	}
	if(min!=9999)
		cost=cost+min;
	
	return nc;
}

void mincost2(int city)
{
	int ncity;
	printf("%d --> ",city);
	vis2[city]=1;
	ncity=least2(city);

	if(ncity==9999)
	{
		ncity=1;
		printf("%d ",ncity);
		cost=cost+a[city][ncity];
		return;
	}
	mincost2(ncity);
}

int least2(int c)
{
	int i,nc=9999,min=9999,kmin;

	for(i=1;i<=n;i++)
	{
		if(a[c][i]!=0 && vis2[i]==0)
		{
			if(a[c][i]<min)
			{	
				min=a[i][1]+a[c][i];
				kmin=a[c][i];
				nc=i;
			}
		}
	}
	
	if(min!=9999)
		cost=cost+kmin;
	
	return nc;
}
	
void main()
{

//	input();
	
	input();
	printf("The approx path is \n");
	mincost1(1);
	printf("The minimum approx cost incurred is %d\n",cost);
	approxcost=cost;
	cost=0;

	printf("The exact path is\n");
	mincost2(1);
	printf("The minimum exact cost incurred is %d\n",cost);
	exactcost=cost;

	error=((approxcost-exactcost)/exactcost)*100.0;
	printf("TH percentage error in approximation is %f\n",error);
		
}
