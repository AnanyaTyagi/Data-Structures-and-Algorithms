#include<stdio.h>
int jobseq(int d[],int j[],int n);
int main()
{
	int n,i,j,k,s,r;
	printf("Enter the number of jobs");
	scanf("%d",&n);
	int d[n+1],p[n+1],q[n+1],job[n+1],t;
	printf("enter deadline of each job");
	for(i=1;i<=n;i++)
	scanf("%d",&d[i]);
	printf("enter profit of each job");
	for(i=1;i<=n;i++)
	scanf("%d",&p[i]);
	for(i=1;i<=n;i++)
	q[i]=p[i];
	for(i=1;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(p[j]<p[j+1])
			{
				t=p[j+1];
				p[j+1]=p[j];
				p[j]=t;
				
				t=d[j+1];
				d[j+1]=d[j];
				d[j]=t;
			}
		}
	}
	k=jobseq(d,job,n);
	for(r=1;r<=k;r++)
	{
		for(s=1;s<=n;s++)
		{
			if(q[job[r]]==p[s])
			{
				printf("%d",s);
				break;
			}
		}
	}
}
int jobseq(int d[],int j[],int n){
	int q,r,k,i;
	d[0]=j[0]=0;
	j[1]=1;
	k=1;
	for(i=2;i<=n;i++)
	{
		r=k;
		if(d[j[r]]>d[i] && d[j[r]]!=r)
		r--;
		if(d[j[r]]<=d[i] && d[i]>r)
		{
			for(q=k;q>=r+1;q--)
			{
				j[q+1]=j[q];
				j[r+1]=i;
				k++;
			}
		}
	}
	return k;	
}
