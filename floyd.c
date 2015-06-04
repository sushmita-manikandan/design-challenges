#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int w[10][10],n;

void floyds1()
{
	int i,j,k;
	#pragma omp parallel for private(i,j,k) shared(w)
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(w[i][j]!=0 && w[i][k]+w[k][j]<w[i][j])
				{
					w[i][j]=w[i][k]+w[k][j];
				}
			}
		}
	}
}

void floyds2()
{
	int i,j,k;
	//#pragma omp parallel for private(i,j,k) shared(w)
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(w[i][j]!=0 && w[i][k]+w[k][j]<w[i][j])
				{
					w[i][j]=w[i][k]+w[k][j];
				}
			}
		}
	}
}

void main()
{
	int i,j;
	struct timeval tv;
	double end1,start1,elapse1,end2,start2,elapse2,sp;

	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the weight matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	
	gettimeofday(&tv,NULL);
	start2=tv.tv_sec+(tv.tv_usec/1000000.0);
	floyds2();
	gettimeofday(&tv,NULL);
	end2=tv.tv_sec+(tv.tv_usec/1000000.0);
	elapse2=end2-start2;
	gettimeofday(&tv,NULL);
	start1=tv.tv_sec+(tv.tv_usec/1000000.0);
	floyds1();
	gettimeofday(&tv,NULL);
	end1=tv.tv_sec+(tv.tv_usec/1000000.0);
	elapse1=end1-start1;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",w[i][j]);
		}
		printf("\n");
	}
	
	sp=((elapse1-elapse2)/elapse1)*100.0;
	printf("The speed up achieved is %lf\n",sp);
}
