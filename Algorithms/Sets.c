#include<stdio.h>
#include<conio.h>
int insert(int a[],int,int);
void sunion(int a[],int,int);
int sfind(int a[],int);
void display(int a[],int,int);
void wtdunion(int a[],int,int);
int colfind(int a[],int);
void main()
{
	int a[100],n,n1,n2,count,ch,i,j,x,key;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	n2=n;
	printf("Enter total number of sets");
	scanf("%d",&n1);
	for(count=1;count<=n;count++)
	a[count]=-999;
	for(count=1;count<=n1;count++)
	{
		printf("Enter %d set:\n",count);
		n2=insert(a,n,n2);
	}
	do{
		printf("1)simple union \n2)Simple find\n3)Display specific set\n4)weighted union\n5)collapse find\n6)exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the values of roots of both trees");
			     scanf("%d%d",&i,&j);
			     sunion(a,i,j);
			      break;
		    case 2:printf("enter the value for find:");
		           scanf("%d",&key);
		           if(key>n)
		           break;
		           x=sfind(a,key);
		           printf("Value is found at %d rooted tree \n",x);
		           break;
		    case 3:printf("enter the value of root:");
		           scanf("%d",&i);
		           printf("elements are:\n");
		           display(a,i,n);
		           printf("\n");
		           break;
		    case 4:printf("enter the root of both trees");
		           scanf("%d%d",&i,&j);
		           wtdunion(a,i,j);
		           break;
		    case 5:printf("enter the value to find");
		           scanf("%d",key);
		           if(key>n)
		           break;
		           x=colfind(a,key);
		           printf("value is found at %d rooted tree\n",x);
		           break;
		}
	}while(ch!=6);
}
int insert(int a[],int n,int n2){
	int root,q=0,j=0,ch,x;
	printf("Do you want to insert:\n1)Yes\n2)no\n");
	scanf("%d",&ch);
	while(n2>0 && ch!=2)
	{
		printf("Enter the value:");
		scanf("%d",&x);
		if(x<1 && x>n)
		{
			printf("Invalid input.");
			continue;
		}
		if(a[x]!=-999)
		{
			printf("value should be unique");
			continue;
		}
		if(j==0)
		{
			a[x]=-1;
			root=x;
		}else
			a[x]=root;
			j++;
			n2--;
			printf("Do you want to insert");
			scanf("%d",&ch);
		
	}
	a[root]=-j;
	return n2;
}
void sunion(int a[],int i,int j){
	a[i]=j;
}
int sfind(int a[],int i){
	while(a[i]>=0)
	{
		i=a[i];
	}
	return i;
}
void wtdunion(int a[],int i,int j){
	int temp;
	temp=a[i]+a[j];
	if(a[i]>a[j])
	{
		a[i]=j;
		a[j]=temp;
	}else{
		a[j]=i;
		a[i]=temp;
	}
}
void display(int a[],int root,int n)
{
	int stack[100],i,x,k,top;
	top=-1;
	stack[++top]=root;
	while(top>=0)
	{
		x=stack[top--];
		for(i=1;i<=n;i++)
		{
			if(a[i]==x)
			{
				stack[++top]=i;
			}
		}
		printf("%d",x);
	}
}
int colfind(int a[],int i){
	int r,s;
	r=i;
	while(a[r]>0)
	{
		r=a[r];
	}
	while(i!=r)
	{
		s=a[i];
		a[i]=r;
		i=s;
	}
	return r;
}
