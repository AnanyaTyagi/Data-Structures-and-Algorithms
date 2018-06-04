#include<stdio.h>
float knapsack(float w[],float p[],int n,float m);
main()
{
	int n,i,j;
	printf("Enter total no. of objects.");
	scanf("%d",&n);
	float w[n],p[n],x[n],m,t,total;
	printf("Enter the capacity of knapsack.");
	scanf("%f",&m);
	printf("Enter the weights of the object");
	for(i=0;i<n;i++)
	{
		scanf("%f",&w[i]);
	}
	printf("Enter the profits of the object");
	for(i=0;i<n;i++)
	{
		scanf("%f",&p[i]);
	}
	for(i=0;i<n;i++)
	{
		x[i]=p[i]/w[i];
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(x[i]<x[i+1])
			{
				t=x[i];
				x[i]=x[i+1];
				x[i+1]=t;
				
				t=w[i];
				w[i]=w[i+1];
				w[i+1]=t;
				
				t=p[i];
				p[i]=p[i+1];
				p[i+1]=t;
			}
		}
	}
	total=knapsack(w,p,n,m);
	printf("Total cost is:%f",total);
}
float knapsack(float w[],float p[],int n,float m){
	float x[n],total=0,u;
	int i;
	u=m;
	for(i=0;i<n;i++)
	x[i]=0;

	for(i=0;i<n;i++)
	{
		if(w[i]>u)
		{
			break;
		}else{
			x[i]=1;
			u=u-w[i];
			total=total+p[i];
		}
	}
	if(i<=n)
	{
		x[i]=u/w[i];
	}
	total=total+p[i]*x[i];
	printf("The resultant vector is:\n");
	for(i=0;i<n;i++)
	{
		printf("%f\t",x[i]);
	}
	return total;
}
