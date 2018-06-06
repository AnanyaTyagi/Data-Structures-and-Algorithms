#include<stdio.h>
int prim(int cost[][100],int v,int t[][100]);
main()
{
	int v,cost[100][100],n,i,j,t[100][100],x;
	printf("Enter number of vertices:\n");
	scanf("%d",&v);
	printf("Enter the cost of vertices:\n");
	printf("If  no edge enter 9999:\n");	
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(i==j)
			{
				cost[i][j]=0;
			}else if(j>i)
			{
				printf("Enter cost between %d and %d vertices",i,j);
				scanf("%d",&cost[i][j]);
				cost[j][i]=cost[i][j];
			}
		}
	}
	x=prim(cost,v,t);
	printf("The mincost is:",x);
	for(i=1;i<=v-1;i++)
	{
		for(j=1;j<=2;j++)
		{
			printf("%d",t[i][j]);
		}
		printf("\n");
	}
}
int prim(int cost[][100],int v,int t[][100])
{
	int i,j,m,near[v+1],mincost,min,k,l;
	mincost=9999;
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(i>j&&cost[i][j]<mincost)
			{
				mincost=cost[i][j];
				k=i;
				l=j;
			}
		}
	}
	t[1][1]=k;
	t[1][2]=l;
	for(i=1;i<=v;i++)
	{
		if(cost[i][k]>cost[i][l])
		{
			near[i]=l;
		}else{
			near[i]=k;
		}
	}
	near[k]=near[l]=0;
	for(i=2;i<=v-1;i++)
	{
		min=999;
		for(j=1;j<=v;j++)
		{
			if(near[j]!=0&&cost[j][near[j]]!=0&&cost[j][near[j]]<min)
			{
				min=cost[j][near[j]];
				m=j;
			}
		}
		t[i][1]=m;
		t[i][2]=near[m];
		mincost=mincost+cost[m][near[m]];
		near[m]=0;
		for(k=1;k<=v;k++)
		{
			if(near[k]!=0 && cost[k][near[k]]>cost[k][m])
			{
				near[k]=m;
			}
		}
	}
	return mincost;
}
