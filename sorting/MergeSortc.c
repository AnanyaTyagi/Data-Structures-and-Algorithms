#include<stdio.h>
#include<conio.h>
void mergesort(int a[],int lb,int ub);
void merge(int a[],int lb,int mid,int ub);
main()
{
	int i,n,lb,ub;
	printf("enter the size of array");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	lb=0;
	ub=n-1;
	mergesort(a,lb,ub);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
void mergesort(int a[],int lb,int ub)
{
	int j,mid;
	if(lb>=ub)
	return;
	mid=(lb+ub)/2;
  mergesort(a,lb,mid);
  mergesort(a,mid+1,ub);
  merge(a,lb,mid,ub);	
}

void merge(int a[],int lb,int mid,int ub){
	int k,i,j,temp[lb+ub-1];
	i=lb;
	j=mid+1;
	for(k=0;i<=mid&&j<=ub;k++)
	{
		if(a[i]>a[j])
		{
			temp[k]=a[j++];
		}else{
			temp[k]=a[i++];
		}
	}
	for(;j<=ub;k++)
	{
		temp[k]=a[j++];
	}
	for(;i<=mid;k++)
	{
		temp[k]=a[i++];
	}
	k=0;
	for(i=lb;i<=ub;i++)
	{
		a[i]=temp[k++];
	}
}
