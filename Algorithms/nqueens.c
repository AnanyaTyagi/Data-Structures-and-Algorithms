#include<stdio.h>
#include<math.h>
int place(int k,int l,int x[]);
void nqueens(int x[],int k,int n);
int main() 
{
	int n,x[20];
	printf("Enter size of chessboard");
	scanf("%d",&n);
	nqueens(x,1,n);
}
void nqueens(int x[],int k,int n){
	int l,i;
	for(l=1;l<=n;l++)
	{
		if(place(k,l,x))
		{
			x[k]=l;
			if(k==n)
			{
				for(i=1;i<=n;i++)
				{
					printf("%d\t",x[i]);
				}
				printf("\n");
			}else{
				nqueens(x,k+1,n);
			}
		}
	}
} 
int place(int k,int l,int x[]){
	int i;
	for(i=1;i<=k-1;i++)
	{
	 if(x[i]==l || abs(x[i]-l)==abs(i-k))
	 return 0;
	}
	return 1;
}
                     
