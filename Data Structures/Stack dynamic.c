#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node * next;
};
struct node * push(struct node *,int x);
struct node * pop(struct node *);
int empty(struct node *top);
void display(struct node * top);
struct node * getnode(int x);

main()
{
	struct node * top=NULL;
	int ch,x;
	do{
		printf("Enter user choice:1)Push\n2)Pop\n3)Display\n4)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element to be pushed:");
			       scanf("%d",&x);
			       top=push(top,x);
			       break;
			case 2:top=pop(top);
				   break;
		  	case 3:display(top);
		    	   break;
			case 4:break;
		}
	}while(ch!=4);
}
struct node * push(struct node *top,int x){
	struct node *q;
    q=getnode(x);
    if(empty(top))
    {
    	top=q;
	}else{
		q->next=top;
		top=q;
	}
	return top;
}
struct node * pop(struct node *top){
      if(empty(top))
      {
      	printf("List is empty\n");
	  }else{
	  	printf("The popped element is:%d",top->info);
	  	top=top->next;
	  }
	  return top;
}
int empty(struct node *top){
	if(top==NULL)
	{
		return 1;
	}
	return 0;
}
void display(struct node *top){
  if(top==NULL)
  {
	printf("List is empty\n");
  }else{
	struct node *p;
	p=top;
	while(p!=NULL)
	{
		printf("%d\n",p->info);
		p=p->next;
	}
  }
}
struct node * getnode(int x)
{
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
	q->next=NULL;
	q->info=x;
	return q;
}

