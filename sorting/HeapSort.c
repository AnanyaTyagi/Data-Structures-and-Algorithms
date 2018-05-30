#include<stdio.h>
#include<conio.h>
void heapsort(int a[],int n);
void heapify(int a[],int n);
void adjust(int a[],int i,int n);
main()
{
	int i,n;
	printf("enter the size of array");
	scanf("%d",&n);
	int a[n+1];
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	for(i=1;i<=n;i++)
	{
		printf("%d",a[i]);
	}
}
void heapsort(int a[],int n)
{
int i,t;
heapify(a,n);
for(i=n;i>=2;i--)
{
	t=a[i];
	a[i]=a[1];
	a[1]=t;
	adjust(a,1,i-1);
}
}
void adjust(int a[],int i,int n)
{
	int j,item;
	j=2*i;
	item=a[i];
	while(j<=n)
	{
		if((j<n)&&a[j]<a[j+1])
		j++;
		if(item>=a[j])
		{
			break;
		}
		a[j/2]=a[j];
		j=2*j;
	}
	a[j/2]=item;
}
void heapify(int a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		adjust(a,i,n);
	}
}
