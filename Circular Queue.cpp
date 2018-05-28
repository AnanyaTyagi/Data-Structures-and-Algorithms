#include<stdio.h>
#define SIZE 5
void insert(struct node *,int x);
int del(struct node *);
int full(struct node *);
int empty(struct node *);
struct node{
	int items[SIZE];
	int front,rear;
}s;
int main()
{
	struct node *q; 
	s.front=0;
	s.rear=SIZE-1;
	q=&s;
	int ch,x;
	do{
		printf("Enter user choice:1)Insert\n2)Delete\n3)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element to be inserted:");
			       scanf("%d",&x);
			       insert(q,x);
			       break;
			case 2:x=del(q);
			        if(x==-999)
			        {
			        	printf("Stack Underflow\n");
					}else
					{
						printf("%d\n",x);
					}
				   break;
		  	case 3:break;
		}
	}while(ch!=3);
}
void insert(struct node *q,int x){
	if(!(full(q)))
	{
	  q->rear++;
	  q->items[q->rear]=x;	
	}else{
		printf("Stack is full");
	}
}
int del(struct node *q){
	int x=-999;
	if(!(empty(q)))
	{
	  x=q->items[q->front];
	  q->front++;
	  return x;	
	}
	return x;
}
int full(struct node *ps){
	if(ps->front==ps->rear){
		return 1;
	}
	return 0;
}
int empty(struct node *q){
	if((q->rear+1)%SIZE==q->front)
	{
		return 1;
	}
	return 0;
}

