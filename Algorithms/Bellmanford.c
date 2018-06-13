#include<stdio.h>
void bellmanford(int v,int cost[][100],int dist[100],int n);
main()
{
	int cost[100][100],dist[100],n,i,j,v;
	printf("Enter no. of vertices");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			{
				cost[i][j]=0;
			}else{
				printf("Enter cost between %d and %d",i,j);
				scanf("%d",&cost[i][j]);
			}
		}
	}
	printf("Enter source vertex");
	scanf("%d",&v);
	bellmanford(v,cost,dist,n);
	for(i=1;i<=n;i++)
	{
			printf("%d\n",dist[i]);
    }
}
void bellmanford(int v,int cost[][100],int dist[100],int n)
{
	int i,j,k,u;
    for(i=1;i<=n;i++)
    {
    	dist[i]=cost[v][i];
	}
	for(k=2;k<=n-1;k++)
	{
		for(u=1;u<=n;u++)
		{
			if(u!=v)
			{
				for(i=1;i<=n;i++)
				{
					if(cost[i][u]!=999 || cost[i][u]!=0)
					{
						if(dist[u]>dist[i]+cost[i][u])
						dist[u]=dist[i]+cost[i][u];
					}
				}
			}
		}
	}
}
