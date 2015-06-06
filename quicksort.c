#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

void swap(int *x, int *y)
{
	int temp;
	temp= *x;
	*x=*y;
	*y=temp;
}

int partition(int a[], int low, int high)
{
	//printf("Entering partition\n");
	int i,j,key;

	i=low+1;
	j=high;
	key=a[low];

	while(i<=j)
	{
		//printf("Entering 1st while \n");
		while(a[i]<=key)
			i++;	
		//printf("Entering 2ndwhile \n");
		while(a[j]>key)
			j--;
		//printf("Out of the inner while loops\n");
		if(i<=j)
			swap(&a[i],&a[j]);
		//printf("Done with parse\n");
	}
	//printf("Outside while\n");
	swap(&a[low],&a[j]);
	return j;
}

void quicksort(int a[],int low,int high)
{
	//printf("Entering quicksort\n");
	int p;
	if(low<=high)
	{
		//printf("Inside loop before partition\n");
		p=partition(a,low,high);
		quicksort(a,low,p-1);
		//printf("Done with the left half\n");
		quicksort(a,p+1,high);
		//printf("Done with the right half\n");
	}
	return;
}

void gen_random(int a[],int i)
{
	int n;
	for(n=0;n<i;n++)
		a[n]=rand()%100;
}

int main()
{
	int i,n,a[1500];
	struct timeval tv;
	double start,end,elapse;
	FILE *fp;
	fp=fopen("graph.txt","w");
	
	for(i=100;i<=1000;i=i+100)
	{
		gen_random(a,i);
		gettimeofday(&tv,NULL);
		start=tv.tv_sec+(tv.tv_usec/1000000.0);
		/*for(n=0;n<i;n++)
		printf("%d\n",a[n]);*/
		quicksort(a,0,i-1);
		/*for(n=0;n<i;n++)
		printf("%d\n",a[n]);*/
		gettimeofday(&tv,NULL);
		end=tv.tv_sec+(tv.tv_usec/1000000.0);
		//printf("Done with the left half\n");
		elapse=end-start;
		printf("%d\t%lf\n",i,elapse);
		fprintf(fp,"%d\t%lf\n",i,elapse);
	}
	fclose(fp);
	system("gnuplot");
	return 0;

}
