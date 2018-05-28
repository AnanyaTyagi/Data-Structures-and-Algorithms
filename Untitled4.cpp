#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node * next;
};
void display(struct node *p);
struct node * insertbeg(struct node *p,int x);
struct node * insertafter(struct node *p,int x,int y);
struct node * insertend(struct node *p,int x);
void delbeg(struct node *p);
struct node * delend(struct node *p);
struct node * delnode(struct node *q,int x);
struct node * getnode(int x);
main()
{
 struct node *p,*head;
 head=NULL;
 int ch,x,y;
	do{
		printf("Enter user choice:1)Insert at beginning\n2)Insert After\n3)Insert at end\n4)Delete from beginning\n5)Delete a particular node\n6)Delete end7)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element to be inserted:");
			       scanf("%d",&x);
			       head=insertbeg(head,x);
			       break;
			case 2:printf("Enter element to be inserted:");
			       scanf("%d",&x);
			       printf("Enter element after which the element is to be inserted:");
			       scanf("%d",&y);
			       head=insertafter(head,x,y);
			       break;
			case 3:printf("Enter element to be inserted:");
			       scanf("%d",&x);
			       head=insertend(head,x);
			case 4:delbeg(head);
			case 5:printf("Enter element to be deleted:");
			       scanf("%d",&x);
			       delnode(head,x);
		    case 6:delend(head);      
		  	case 7:break;
		}
	}while(ch!=7);	
}
void display(struct node *head)
{
	struct node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->info);
		p=p->next;
	}
}
struct node * insertbeg(struct node *head,int x){
	struct node *q;
	q=getnode(x);
	q->next=head;
	head=q;
	return head;
}
struct node * insertafter(struct node *head,int x,int y){
	struct node *p,*q;
	q=getnode(x);
	p=head;
	while(p->info!=y||p!=NULL)
	{
		p=p->next;
	}
	if(p==NULL){
		printf("Element not found");
		return head;
	}else{
	  q->next=p->next;
	  p->next=q;
	  return  head;	
	}
}
struct node * insertend(struct node *head,int x){
	struct node *p,*q;
	q=getnode(x);
	p=head;
	if(p==NULL)
	{
		p=q;
		return p;
	}else{
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=q;
	return head;
    }
}
struct node * delbeg(struct node *p,int x);
struct node * delend(struct node *p,int x);
struct node * delvalue(struct node *q,int x);
struct node * getnode(int x){
	struct node *q;
	q = (struct node *) malloc(sizeof(struct node));
	q->info=x;
	q->next=NULL;
	return q;
}
