#include<stdio.h>
#include<conio.h>
void quicksort(int a[],int lb,int ub);
int partition(int a[],int lb,int ub);
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
	quicksort(a,lb,ub);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
void quicksort(int a[],int lb,int ub)
{
	int j;
	if(lb>ub)
	return;
  j=partition(a,lb,ub);
  quicksort(a,lb,j-1);
  quicksort(a,j+1,ub);	
}
int partition(int a[],int lb,int ub){
	int up,down,arr,t;
	up=ub;
	down=lb;
	arr=a[lb];
	while(up>down)
	{
		while(a[down]<=arr)
		down++;
		while(a[up]>arr)
		up--;
		if(down<up)
		{
			t=a[down];
			a[down]=a[up];
			a[up]=t;
		}
	}
	t=a[lb];
	a[lb]=a[up];
	a[up]=t;
	return up;
}
