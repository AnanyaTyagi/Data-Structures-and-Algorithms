#include<stdio.h>
#include<conio.h>
void radixsort(int a[],int n);
int maximum(int a[],int n);
main()
{
	int i,n;
	printf("enter the size of array");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	radixsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
void radixsort(int a[],int n)
{
	int max,digit,divisor=1,count[10],bucket[10][n],i,j,k,l,numdigits=0;
	max=maximum(a,n);
	while(max>0)
	{
		numdigits++;
		max=max/10;
	}
	for(i=0;i<numdigits;i++)
	{
		for(j=0;j<10;j++)
		{
			count[j]=0;
		}
		for(j=0;j<n;j++)
		{
			digit=(a[j]/divisor)%10;
			bucket[digit][count[digit]]=a[j];
			count[digit]++;
		}
		j=0;
		for(l=0;l<10;l++)
		{
			for(k=0;k<count[l];k++)
			{
				a[j]=bucket[l][k];
				j++;
			}
		}
		divisor*=10;
	}
}
int maximum(int a[],int n)
{
	int max,i;
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	return max;
}
