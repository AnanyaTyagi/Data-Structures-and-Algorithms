#include<stdio.h>
#include<conio.h>
void bubblesort(int a[],int n);
int binarysearch(int a[],int low,int high,int x);
main()
{
	int a[10],i,n,x,l,u,y;
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
	y=binarysearch( a,l, u, x);
	if(y==-1)
	{
		printf("element not found");
	}else{
		printf("Element found at:%d",y+1);
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
int binarysearch(int a[],int low,int high,int x){
	int mid;
	if(low>high)
	return -1;
	mid=(low+high)/2;
	return(a[mid]==x?mid:(a[mid]>x?binarysearch(a,low,mid-1,x):binarysearch(a,mid+1,high,x)));
}
