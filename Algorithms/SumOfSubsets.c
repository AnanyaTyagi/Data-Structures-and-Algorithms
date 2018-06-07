#include<stdio.h>
void sumofsubsets(int x[],int w[],int m,int s,int k,int r,int n);
int main()
{
	int i,j,n,x[100],w[100],t,m,s=0,r=0;
	printf("Enter size of objects");
	scanf("%d",&n);
	printf("Enter weights:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i-1;j++)
		{
			if(w[j]>w[j+1])
			{
				t=w[j];
				w[j]=w[j+1];
				w[j+1]=t;
			}
		}
	}
	printf("Enter capacity");
	scanf("%d",&m);
	for(i=1;i<=n;i++)
	r=r+w[i];
	sumofsubsets(x,w,m,s,1,r,n);
}
void sumofsubsets(int x[],int w[],int m,int s,int k,int r,int n){
	int i;
	x[k]=1;
	if(s+w[k]==m)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d\t",x[i]*w[i]);
		}
		printf("\n");
	}
	else{
		if(s+w[k]+w[k+1]<=m)
		{
			sumofsubsets(x,w,m,s+w[k],k+1,r-w[k],n);
		}
	}
	if(s+w[k+1]<=m && (s+r-w[k]>=m))
	{
		x[k]=0;
		sumofsubsets(x,w,m,s,k+1,r-w[k],n);
	}
}
