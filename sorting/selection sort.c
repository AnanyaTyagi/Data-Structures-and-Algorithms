#include<stdio.h>
#include<conio.h>
void selectionsort(int a[10],int n);
main()
{
	int a[10],i,n;
	printf("enter the size of array");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selectionsort(a,n);
}
void selectionsort(int a[10],int n)
{
	int min;
	int i,j,t;
	for(i=0;i<n-1;i++)
	{ 
	     min=i;
	    for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		t=a[min];
		a[min]=a[i];
		a[i]=t;
	}
	printf("sorted array is");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
