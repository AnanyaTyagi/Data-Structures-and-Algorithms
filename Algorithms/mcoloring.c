#include<stdio.h>
void mcoloring(int x[],int k,int g[][100],int m,int n);
void nextvalue(int x[],int k,int g[][100],int m,int n);
int main(){
	int i,j,g[100][100],n,x[100],k,m;
	printf("Enter no. of vertices");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			{
				g[i][j]=0;
			}else if(j>i){
				printf("g[%d][%d]:\n",i,j);
				scanf("%d",&g[i][j]);
				g[j][i]=g[i][j];
			}
		}
  }
    printf("Enter the chromatic no.:");
    scanf("%d",&m);
	mcoloring(x,1,g,m,n);
}
void mcoloring(int x[],int k,int g[][100],int m,int n){
	int j,i;
	while(1)
	{
		nextvalue(x,k,g,m,n);
		if(x[k]==0)
		return;
		if(k==n)
		{
			for(i=1;i<=n;i++)
			printf("%d\t",x[i]);
			printf("\n");
		}else
		{
			mcoloring(x,k+1,g,m,n);
		}
	}
}
void nextvalue(int x[],int k,int g[][100],int m,int n){
	int i,j;
	while(1)
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
		{
			return;
		}
        for(j=1;j<=n;j++)
        {
        	if(g[k][j]!=0 && x[k]==x[j])
        	{
        		break;
			}
		}if(j==n+1)
		return;
	}
}
