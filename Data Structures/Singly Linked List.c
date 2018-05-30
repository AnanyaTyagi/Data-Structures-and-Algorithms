/#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node * next;
};
struct node * display(struct node *p);
struct node * insertbeg(struct node *p,int x);
struct node * insertafter(struct node *p,int x,int y);
struct node * insertend(struct node *p,int x);
struct node * delbeg(struct node *p);
struct node * delend(struct node *p);
struct node * delnode(struct node *q,int x);
struct node * getnode(int x);
main()
{
 struct node *p,*head;
 head=NULL;
 int ch,x,y;
	do{
		printf("Enter user choice:1)Insert at beginning\n2)Insert After\n3)Insert at end\n4)Delete from beginning\n5)Delete a particular node\n6)Delete end\n7)Display\n8)xit\n");
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
			       break;
			case 4:head=delbeg(head);
			       break;
			case 5:printf("Enter element to be deleted:");
			       scanf("%d",&x);
			       head=delnode(head,x);
			       break;
		    case 6:head=delend(head);
			       break;      
		  	case 7:head=display(head);
			       break;
			case 8:break;
		}
	}while(ch!=8);	
}
struct node * display(struct node *head)
{
	struct node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->info);
		p=p->next;
	}
	return head;
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
	while(p->info!=y)
	{
		p=p->next;
    }
	q->next=p->next;
	p->next=q;
	return head;
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
struct node * delbeg(struct node *head){
	struct node *p;
	p=head;
    head=head->next;
	free(p); 
	return head;	
}
struct node * delend(struct node *head){
	struct node *p,*r;
	p=head;
	while(p->next!=NULL)
	{  
	    r=p;
		p=p->next;	
	}
	free(p);
	r->next=NULL;
	return head;
}
struct node * delnode(struct node *head,int x){
	struct node *p,*r;
	p=head;
	while(p->info!=x)
	{
		r=p;
		p=p->next;
	}
	r->next=p->next;
	free(p);
	return head;
}
struct node * getnode(int x){
	struct node *q;
	q = (struct node *)malloc(sizeof(struct node));
	q->info=x;
	q->next=NULL;
	return q;
}
