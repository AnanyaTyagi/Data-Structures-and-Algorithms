void Dijkstra(int v,int cost[][100],int dist[],int n);
main()
{
	int v,cost[100][100],n,i,j,dist[100];
	printf("Enter number of vertices:\n");
	scanf("%d",&n);
	printf("Enter the cost of vertices:\n");
	printf("If  no edge enter 9999:\n");	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			{
				cost[i][j]=0;
			}else
			{
				printf("Enter cost between %d and %d vertices",i,j);
				scanf("%d",&cost[i][j]);
			}
		}
	}
	printf("Enter source vertex:");
	scanf("%d",&v);
	Dijkstra(v,cost,dist,n);
	for(i=1;i<=n;i++)
	{
			printf("%d",dist[i]);
	}
}
void Dijkstra(int v,int cost[][100],int dist[],int n){
	int s[100],u,w,i,j,min;
	for(i=1;i<=n;i++)
	{
		dist[i]=cost[v][i];
	}
	dist[v]=0;
	for(i=1;i<=n;i++)
	{
		s[i]=0;
	}
	s[v]=1;
	for(i=2;i<=n;i++)
	{
		min=999;
		for(j=1;j<=n;j++)
		{
			if(dist[j]!=0 && s[j]==0 &&dist[j]<min)
			{
				min=dist[j];
				u=j;
			}	
		}
		s[u]=1;
		for(w=1;w<=n;w++)
		{
			if(cost[u][w]!=9999 && s[w]==0)
			{
				if(dist[w]>dist[u]+cost[u][w])
				{
					dist[w]=dist[u]+cost[u][w];
				}
			}
		}
	}
}
