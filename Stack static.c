#include<stdio.h>
#define SIZE 10
void push(struct node *,int x);
int pop(struct node *);
int full(struct node *);
int empty(struct node *);
void display(struct node *);
struct node{
	int items[SIZE];
	int top;
}s;
int main()
{
	struct node *ps;
    s.top=-1;
	ps=&s; 
	int ch,x;
	do{
		printf("Enter user choice:1)Push\n2)Pop\n3)Display\n4)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element to be pushed:");
			       scanf("%d",&x);
			       push(ps,x);
			       break;
			case 2:x=pop(ps);
			        if(x==-999)
			        {
			        	printf("Stack Underflow\n");
					}else
					{
						printf("%d\n",x);
					}
				   break;
		  	case 3:display(ps);
		    	   break;
			case 4:break;
		}
	}while(ch!=4);
}
void push(struct node *ps,int x){
	if(!(full(ps)))
	{
	  ++ps->top;
	  ps->items[ps->top]=x;	
	}else{
		printf("Stack is full");
	}
}
int pop(struct node *ps){
	int x=-999;
	if(!(empty(ps)))
	{
	  x=ps->items[ps->top];
	  ps->top--;
	  return x;	
	}
	return x;
}
int full(struct node *ps){
	if(ps->top==SIZE-1){
		return 1;
	}
	return 0;
}
int empty(struct node *ps){
	if(ps->top==-1)
	{
		return 1;
	}
	return 0;
}
void display(struct node *ps){
int i;
for(i=ps->top;i>=0;i--)
{
	printf("%d\n",ps->items[i]);
}
}
