#include<stdio.h>
#include<conio.h>
void bubblesort(int a[10],int n);
main()
{
	int a[10],i,n;
	printf("enter the size of array");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubblesort(a,n);
}
void bubblesort(int a[10],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("sorted array is");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
