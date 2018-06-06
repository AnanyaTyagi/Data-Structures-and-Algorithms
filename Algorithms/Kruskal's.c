#include<stdio.h>
struct node{
	int u,t;
	float cost;
};
int kruskal(struct node a[],int v,int n,int t[][3]);
void heapify(struct node a[],int n);
void adjust(struct node a[],int i,int n);
void sunion(int a[],int i,int j);
int sfind(int a[],int i);
struct node del(struct node a[],int n);

main()
{
	int n,v,x,i,t[100][3];
	struct node a[100];
	printf("Enter no. of vertices");
	scanf("%d",&v);
	printf("Enter no. of edges");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the vertex 1 of edge %d:",i);
		scanf("%d",&a[i].u);
		printf("Enter the vertex 2 of edge %d:",i);
		scanf("%d",&a[i].t);
		printf("Enter the cost of edge %d:",i);
		scanf("%d",&a[i].cost);
	}
	x=kruskal(a,v,n,t);
	printf("The minimum cost is:",x);
}
int kruskal(struct node a[],int v,int n,int t[][3]){
	int parent[100],i,mincost,j,k;
	struct node px;
	for(i=1;i<=v;i++)
	{
		parent[i]=-1;
	}
	i=0;
	mincost=0;
	while(n>0 && i<v-1)
	{
		px=del(a,n);
		j=sfind(parent,px.u);
		k=sfind(parent,px.t);
		if(j!=k)
		{
			i++;
			t[i][1]=px.u;
			t[i][2]=px.t;
			mincost=mincost+px.cost;
			sunion(parent,j,k);
		}
	}
	if(i!=v-1)
	printf("Not a spanning tree");
	else
    return mincost;	
}
void heapify(struct node a[],int n){
   int i;
   for(i=n/2;i>=1;i++)
   {
   	 adjust(a,i,n);
   }
}
void adjust(struct node a[],int i,int n){
     int j;
	 struct node item;
	 j=2*i;
	 item=a[i];
	 while(j<=n)
	 {
	 	if(a[j].cost>a[j+1].cost)
	 	j++;
	 	if(item.cost<a[j].cost)
	 	break;
	 	a[j/2]=a[j];
	 	j=2*j;
	 }
	 a[j/2]=item;	
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
struct node del(struct node a[],int n){
struct node x;
	x=a[1];
	a[1]=a[n];
	adjust(a,1,n-1);
	return x;
}
