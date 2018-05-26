#include<stdio.h>
#include<conio.h>
void insertionsort(int a[10],int n);
main()
{
	int a[10],i,n;
	printf("enter the size of array");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertionsort(a,n);
}
void insertionsort(int a[10],int n)
{
	int i,j,x;
	for(i=0;i<n;i++)
	{
		x=a[i];
		j=i-1;
		while(a[j]>x&&j>=0)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=x;
	}
	printf("sorted array is");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
