#include<stdio.h>
int insert(int a[],int n,int x);
int del(int a[],int n,int *y);
void adjust(int a[],int i,int n);
int main()
{
	int a[50],n=0,x,ch,y;
	do{
		printf("Enter your choice:\n1)Insert\n2)Delete\n3)Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element to be inserted:");
			       scanf("%d",&x);
			       n=insert(a,n,x);
			       break;
			case 2:n=del(a,n,&y);
			       if(y==-999)
			       printf("Heap is empty");
			       else{
			       	printf("The deleted element is:%d",y);
				   }
			       break;
			case 3:break;
		}
	}while(ch!=3);
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

