#include<stdio.h>
#include<conio.h>
void bubblesort(int a[10],int n);
main()
{
	int a[10],i,n,x,l,u,m;
	printf("enter the size of array");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the element to be searched:");
	scanf("%d",&x);
	bubblesort(a,n);
	l=0;
	u=n-1;
	while(l<=u)
	{
		m=(l+u)/2;
		if(a[m]==x)
		{
			printf("The element is found at:%d",m+1);
			break;
		}
		if(a[m]<x)
		{
			l=m+1;
		}else{
			u=m-1;
		}
		if(l>u)
		{
			printf("the element is not present");
		}
	}
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
}
