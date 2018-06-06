#include<stdio.h>
struct queue
{
	int items[20];
	int front,rear;
};
void bft(int adj[][10],int v);
void bfs(int i,int visited[],int v,int adj[][10]);
void insert(struct queue *pq,int x,int v);
int rem(struct queue *pq);
int full(struct queue *pq,int v);
int empty(struct queue *pq);
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
	bft(adj,v);
}
void bft(int adj[][10],int v)
{
	int i,visited[20];
	for(i=1;i<=v;i++)
	{
		visited[i]=0;
	}
	for(i=1;i<=v;i++)
	{
		if(visited[i]==0)
		bfs(i,visited,v,adj);
	}
}
void bfs(int i,int visited[],int v,int adj[][10])
{
	int j,k,x;
	struct queue q;
	q.front=0;
	q.rear=-1;
	visited[i]=1;
	insert(&q,i,v);
	while(!empty(&q))
	{
		x=rem(&q);
	    printf("%d\n",x);
	   for(k=1;k<=v;k++)
		{
		   	  if(visited[k]==0 && adj[x][k]==1)
		   	  {
		   	  	visited[k]=1;
		   	  	insert(&q,k,v);
			  }
		}
    }
}
void insert(struct queue *pq,int x,int v)
{
	if(!full(pq,v))
	{
	++(pq->rear);
	pq->items[pq->rear]=x;
    }
    else
	return;
}
int rem(struct queue *pq)
{
	int x=-999;
	if(!empty(pq))
	{
		x=pq->items[pq->front];
		++(pq->front);
		return x;
	}
}
int full(struct queue *pq,int v)
{
	if((pq->rear)==v-1)
	return 1;
	return 0;
}
int empty(struct queue *pq)
{
	if((pq)->rear<(pq->front))
	return 1;
	return 0;
}
