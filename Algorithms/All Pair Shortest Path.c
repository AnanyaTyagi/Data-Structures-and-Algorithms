#include<stdio.h>
void allpaths(int cost[][100],int a[][100],int n);
main()
{
	int cost[100][100],a[100][100],n,i,j;
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
	allpaths(cost,a,n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\n",a[i][j]);
	    }
    }
}
void allpaths(int cost[][100],int a[][100],int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=cost[i][j];
	    }
    }
   	for(k=1;k<=n;k++)
   	{
	  for(i=1;i<=n;i++)
	   {
		for(j=1;j<=n;j++)
		{	
			if((a[i][j])>(a[i][k]+a[k][j]))
			{
			 a[i][j]=a[i][k]+a[k][j];
			}
	    }
       }
   }
}
