#include<stdio.h>
int partition(int a[],int low,int high);
int select(int a[],int n,int k);
int max(int a[],int n);
int main()
{
	int n,k,i,x;
	printf("Enter the size of array");
	scanf("%d",&n);
	int a[n];
	printf("Enter the value of K:");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	x=select(a,n,k);
	printf("The %dth smallest element is:%d",k,x);
}
int partition(int a[],int low,int high){
	int up,down,arr,t;
	up=high;
	down=low;
	arr=a[low];
	while(down<up)
	{
		while(arr<=a[down] && down<high)
		down++;
		while(arr>a[up])
		up--;
		if(down<up)
		{
			t=a[up];
			a[up]=a[down];
			a[down]=t;
		}
	}
a[low]=a[up];
a[up]=arr;
return up;
}
int select(int a[],int n,int k){
	int j,low,high;
	a[n]=max(a,n)+1;
	low=0;
	high=n;
	do{
		j=partition(a,low,high);
		if(j==k){
		return a[k];	
		}
		else if(j>k){
			high=j;
		}else{
			low=j+1;
		}
	}while(1);
}
int max(int a[],int n){
	int maximum,i;
	maximum=a[0];
	for(i=1;i<n;i++)
	{
		if(maximum<a[i])
		{
			maximum=a[i];
		}
	}
	return maximum;
}
