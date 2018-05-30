#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node * next;
};
struct node * insert(struct node *,int x);
struct node * del(struct node *);
int empty(struct node *front);
void display(struct node * front);
struct node * getnode(int x);

main()
{
	struct node * front=NULL;
	int ch,x;
	do{
		printf("Enter user choice:1)Insert\n2)Delete\n3)Display\n4)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element to be pushed:");
			       scanf("%d",&x);
			       front=insert(front,x);
			       break;
			case 2:front=del(front);
				   break;
		  	case 3:display(front);
		    	   break;
			case 4:break;
		}
	}while(ch!=4);
}
struct node * insert(struct node *front,int x){
	struct node *q,*p;
    q=getnode(x);
    if(empty(front))
    {
    	front=q;
	}else{
		p=front;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=q;
	}
	return front;
}
struct node * del(struct node *front){
      if(empty(front))
      {
      	printf("List is empty\n");
	  }else{
	  	printf("The deleted element is:%d",front->info);
	  	front=front->next;
	  }
	  return front;
}
int empty(struct node *front){
	if(front==NULL)
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

