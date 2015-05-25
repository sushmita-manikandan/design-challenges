#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int b[2000];

void merge(int a[],int low,int mid, int high)
{
	//printf("Entering merge\n");
	int i,j,k,x;
	k=low;
	i=low;
	j=mid+1;

	while(i<=mid && j<=high)
	{
		//printf("Entering 1\n");
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	//printf("Entering 2\n");
	if(i<=mid)
	{
		while(i<=mid)
		b[k++]=a[i++];
	}
	else
	{
		while(j<=high)
		b[k++]=a[j++];
	}

	for(x=low;x<=high;x++)
		a[x]=b[x];
	
}

void mergesort(int a[],int low,int high)
{
	int mid;
	//printf("Entering mergesort\n");
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		//printf("Done with the lower half\n");
		mergesort(a,mid+1,high);
		//printf("Done with the upper half\n");
		merge(a,low,mid,high);
		//printf("Done with merging\n");
	}

}

void gen_random(int a[],int i)
{
	int n;
	for(n=0;n<i;n++)
		a[n]=rand()%100;
}

void main()
{
	int i,n,a[2000];
	struct timeval tv;
	FILE *fp;
	fp=fopen("graph.txt","w");
	double end,start,elapse;
	for(i=100;i<=1000;i=i+100)
	{
		gen_random(a,i);

		gettimeofday(&tv,NULL);
		start=tv.tv_sec+(tv.tv_usec/1000000.0);
	
		mergesort(a,0,i-1);
		gettimeofday(&tv,NULL);

		end=tv.tv_sec+(tv.tv_usec/1000000.0);
		elapse=end-start;
		printf("i=%d \t elapse=%lf \n",i,elapse);
		fprintf(fp,"%d\t%lf\n",i,elapse);
	}
	fclose(fp);
	system ("gnuplot");
}
