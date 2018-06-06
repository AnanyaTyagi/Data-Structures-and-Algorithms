#include<stdio.h>
void dft(int adj[][10],int v);
void dfs(int i,int visited[],int v,int adj[][10]);
main()
{
	int u,v,e,adj[10][10],i,j,t;
	printf("Enter the no. of vertices");
	scanf("%d",&v);
	printf("Enter 1 if edge exists and 0 of it doesn't exist\n");
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
		if(i==j)
		    {
			 adj[i][j]=0;
	    	}
	    	else if(j>i)
	    	{
	    		printf("Is there edge between %d and %d?\n",i,j);
	    		scanf("%d",&adj[i][j]);
	    		adj[j][i]=adj[i][j];
			}
	    }
	}
	dft(adj,v);
}
void dft(int adj[][10],int v)
{
	int i,visited[20];
	for(i=1;i<=v;i++)
	{
		visited[i]=0;
	}
	for(i=1;i<=v;i++)
	{
		if(visited[i]==0)
		dfs(i,visited,v,adj);
	}
}
void dfs(int i,int visited[],int v,int adj[][10])
{
	int j;
	visited[i]=1;
	for(j=1;j<=v;j++)
	{
		if(adj[j][i]==1)
		{
			if(visited[j]==0)
			{
			printf("%d\n",j);
			dfs(j,visited,v,adj);
			}
		}
	}
}
