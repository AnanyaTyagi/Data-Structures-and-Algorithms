#include<stdio.h>
void hamiltonian(int x[],int k,int g[][100],int n);
void nextvalue(int x[],int k,int g[][100],int n);
int main(){
	int i,j,g[100][100],n,x[100],k;
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
	printf("Enter source vertex");
	scanf("%d",&k);
	x[1]=k;
	for(i=2;i<=n;i++)
	x[i]=0;
	hamiltonian(x,2,g,n);
}
void hamiltonian(int x[],int k,int g[][100],int n){
	int j,i;
	while(1)
	{
		nextvalue(x,k,g,n);
		if(x[k]==0)
		return;
		if(k==n)
		{
			for(i=1;i<=n;i++)
			printf("%d\t",x[i]);
			printf("\n");
		}else
		{
			hamiltonian(x,k+1,g,n);
		}
	}
}
void nextvalue(int x[],int k,int g[][100],int n){
	int i,j;
	while(1)
	{
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0)
		{
			return;
		}
		if(g[x[k-1]][x[k]]!=0)
		{
			for(j=1;j<=k-1;j++)
			{
				if(x[j]==x[k])
				break;
			}
			if(j==k){
				if(k<n || (k==n && g[x[n]][x[1]]))
				{
					return;
				}	
			}
		}
	}
}
