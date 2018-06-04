#include<stdio.h>
int insert(int a[],int n,int x);
int del(int a[],int n,int *y);
void adjust(int a[],int i,int n);
void insertsort(int a[],int n);
int main()
{
   int n,i;
   printf("Enter size of array:");
   scanf("%d",&n);
   int a[n];
   insertsort(a,n);
   for(i=1;i<=n;i++)
   {
   	 printf("%d\n",a[i]);
   }
}
int insert(int a[],int n,int x){
	int i,item;
	n=n+1;
	a[n]=x;
	i=n;
	item=a[n];
	while(i>1 && a[i/2]<item)
	{
		a[i]=a[i/2];
		i=i/2;
	}
	a[i]=item;
	return n;
}
int del(int a[],int n,int *y){
	if(n==0)
	{
		*y=-999;
		return n;
	}
	*y=a[1];
	a[1]=a[n];
	n=n-1;
	adjust(a,1,n);
	return n;
}
void adjust(int a[],int i,int n){
     int j,item;
	 j=2*i;
	 item=a[i];
	 while(j<=n)
	 {
	 	if(a[j]<a[j+1])
	 	j++;
	 	if(item>a[j])
	 	break;
	 	a[j/2]=a[j];
	 	j=2*j;
	 }
	 a[j/2]=item;	
}
void insertsort(int a[],int n){
	int i,x,y;
	for(i=0;i<n;i++)
	{
		printf("Enter element to be inserted:");
		scanf("%d",&x);
		insert(a,n,x);
	}
	for(i=n;i>=1;i--)
	{
		del(a,i,&y);
		a[i]=y;
	}
}
