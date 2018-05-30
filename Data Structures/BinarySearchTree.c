#include<stdio.h>
#include<stdlib.h>
#define size 100
struct node
{
	int info;
	struct node * left,* right;
};
struct stack
{
	struct node * items[size];
	int top;
};
struct node * pop(struct stack *ps);
int full(struct stack *ps);
int empty(struct stack *ps);
void push(struct stack *ps,struct node * x);
void inorder(struct node * tree);
void preorder(struct node * tree);
void postorder(struct node * tree);
void pretrav(struct node * tree);
void intrav(struct node * tree);
void posttrav(struct node * tree);
void setleft(struct node *p,int x);
void setright(struct node *p,int x);
struct node * insert(struct node * tree,int x);
struct node * getnode(int x);
struct node * searchmin(struct node * tree);
struct node * searchmax(struct node * tree);
int countleaves(struct node * tree);
int countnonleaves(struct node * tree);
int countnodes(struct node * tree);
int depth(struct node * tree);
struct node * deltree(struct node * tree);
struct node * mirrorimage(struct node * tree);
struct node * search(struct node * tree,int x);
struct node * del(struct node *tree,int x);
main()
{
	struct node * tree,*mirror,*z,*p;
	int x,ch;
	tree=NULL;
	z=NULL;
	do{
		printf("1)Insert \n 2)in traversal \n 3)post traversal \n 4)pre traversal \n 5)search minimum element \n 6)search maximum element \n 7)count no. of leaf nodes\n 8)count non leaves \n 9)count no. of nodes \n 10)depth of tree \n 11)create mirror image \n 12)search the element \n 13)delete the element \n 14)delete whole tree \n15)inorder non recursive\n16)preorder non recursive\n17)postorder non recursive\n 18)exit\n");
		printf("enter user choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the value to be inserted");
			       scanf("%d",&x);
			       tree=insert(tree,x);
			       break;
			case 2:intrav(tree);
			       break;
			case 3:posttrav(tree);
		          	break;
			case 4:pretrav(tree);
			       break;
			case 5:p=searchmin(tree);
                   printf("min no is %d",p->info);
                   break;
			case 6:p=searchmax(tree);
                   printf("max no is %d",p->info);
                   break;
			case 7:x=countleaves(tree);
			       printf("no of nodes is %d",x);
			       break;
			case 8:x=countnonleaves(tree);
			       printf("no of nodes is %d",x);
			        break;
			case 9:x=countnodes(tree);
                   printf("no of nodes is %d",x);
                   break;
			case 10:printf("the depth of the tree is=%d",depth(tree));
			        break;
			case 11:mirror=mirrorimage(tree);
                    pretrav(mirror);
                    break;
			case 12:printf("enter element to be searched");
			       	scanf("%d",&x);
				    z=search(tree,x);
				    if(z==NULL)
				    printf("value not found");
				    else
				    printf("the value=%d",z->info);
				   	break;
			case 13:printf("enter the element to be deleted");
			        scanf("%d",&x);
			        tree=del(tree,x);
			        printf("the desired node has been deleted");
			        break;
			case 14:printf("the whole tree is has been deleted");
			        tree=deltree(tree);
			        break;
			case 15:inorder(tree);
				    break;
			case 16:preorder(tree);
				    break;
			case 17:postorder(tree);
				    break;
			case 18:break;  
		}
	 }while(ch!=18);
}
void push(struct stack *ps,struct node * p)
{
	if(!full(ps))
	{
		++ps->top;
		ps->items[ps->top]=p;
	}
	else
	{
		printf("stack overflow");
	}
}
struct node * pop(struct stack *ps)
{
	struct node * p;
	if(!(empty(ps)))
	{
	   p=ps->items[ps->top];
	   (ps->top)--;
	   return p;
	}
}
int full(struct stack *ps)
{
	if(ps->top==size-1)
	return 1;
	return 0;
}
int empty(struct stack *ps)
{
	if(ps->top==-1)
	return 1;
	return 0;
}
void inorder(struct node * tree)
{
      struct node *p;
	  struct stack s;
	  s.top=-1;
	  p=tree;
	  while((s.top!=-1)||(p!=NULL))	
	  {
	  	if(p!=NULL)
	  	{
	  		push(&s,p);
	  		p=p->left;
		}
		else
		{
			p=pop(&s);
			printf("%d",p->info);
			p=p->right;
		}
	  }
}
void preorder(struct node * tree)
{
	struct node *p;
	p=NULL;
	struct stack s;
	s.top=-1;
	if(tree==NULL)
	return;
	push(&s,tree);
	while(!empty(&s))
	{
		p=pop(&s);
		printf("%d",p->info);
		if(p->right!=NULL)
		push(&s,p->right);
		if(p->left!=NULL)
		push(&s,p->left);
	}
}
void postorder(struct node * tree)
{
	  struct node *p;
	  struct stack s;
	  s.top=-1;
	  p=tree;
	  while(p!=NULL)	
	  {
	  	push(&s,p);
	  	if(p->right!=NULL)
	  	{
		p=p->right;
		push(&s,p->right);
	    }
		else
		p=p->left;
      }
      while(s.top>=0)
      {
        p=s.items[s.top];
      	printf("%d",p->info);
      	s.top--;
	  }
      
}
void pretrav(struct node * tree){
	if(tree!=NULL){
	printf("%d\n",tree->info);
	pretrav(tree->left);
	pretrav(tree->right);
}
}
void intrav(struct node * tree)
{  
   if(tree!=NULL){
	intrav(tree->left);
	printf("%d\n",tree->info);
	intrav(tree->right);	
   }	
}
void posttrav(struct node * tree){
	if(tree!=NULL){
	posttrav(tree->left);
	posttrav(tree->right);
	printf("%d\n",tree->info);
}
}
void setleft(struct node *p,int x){
	if(p==NULL)
	{
		printf("Void insertion");
	}else if(p->left!=NULL)
	{
		printf("Invalid Insertion");
	}else{
		p->left=getnode(x);
	}
}
void setright(struct node *p,int x){
	if(p==NULL)
	{
		printf("Void insertion");
	}else if(p->right!=NULL)
	{
		printf("Invalid Insertion");
	}else{
		p->right=getnode(x);
	}
}
struct node * insert(struct node * tree,int x){
	struct node *q,*p,*parent;
	q=getnode(x);
	if(tree==NULL)
	{
		tree=q;
	}else{
		p=tree;
		parent=NULL;
		while(p!=NULL)
		{
			parent=p;
			if(x<p->info)
			p=p->left;
			else
			p=p->right;
		}
		if(x<parent->info)
		parent->left=q;
		else
		parent->right=q;
	}
	return tree;
}
struct node * getnode(int x){
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
	q->info=x;
	q->right=NULL;
	q->left=NULL;
	return q;
}
struct node * searchmin(struct node * tree)
{
	if(tree==NULL || tree->left==NULL){
		return tree;
	}
	return(searchmin(tree->left));
}
struct node * searchmax(struct node * tree){
	
	if(tree==NULL || tree->right==NULL){
		return tree;
	}
	return(searchmin(tree->right));
}
int countleaves(struct node * tree){
	if(tree==NULL)
	return 0;
	else if(tree->left==NULL && tree->right==NULL)
	{
		return 1;
	}else{
		return(countleaves(tree->left)+countleaves(tree->right));
	}	
}
int countnonleaves(struct node * tree){
    if(tree==NULL||(tree->left==NULL&&tree->right==NULL))
    {
    	return 0;
	}else{
		return(1+countnonleaves(tree->left)+countnonleaves(tree->right));
	}
}
int countnodes(struct node * tree){
	  if(tree==NULL)
	  {
	  	return 0;
	  }else{
	  	return(1+countnodes(tree->left)+countnodes(tree->right));
	  }
}
int depth(struct node * tree){
	int leftdepth,rightdepth;
	if(tree==NULL)
	{
		return 0;
	}else{
		leftdepth=depth(tree->left);
		rightdepth=depth(tree->right);
		if(leftdepth>rightdepth)
		return(1+leftdepth);
		else
		return(1+rightdepth);
	}
}
struct node * deltree(struct node * tree){
	if(tree!=NULL)
	{
		deltree(tree->left);
		deltree(tree->right);
		free(tree);
		tree=NULL;
	}
	return tree;
}
struct node * mirrorimage(struct node * tree)
{
	struct node *p;
	if(tree!=NULL)
	{
		mirrorimage(tree->left);
		mirrorimage(tree->right);
		p=tree->left;
		tree->left=tree->right;
		tree->right=p;
		
	}
	return tree;
}
struct node * search(struct node * tree,int x){
	if(tree==NULL)
	{return NULL;
	}
	 if(tree->info==x){
		return tree;
	}
	if(x<tree->info)
		return(search(tree->left,x));
	if(x>tree->info)
		return(search(tree->right,x));
}
struct node * del(struct node *tree,int x){
	struct node *p,*q,*parentsuc,*suc,*parent;
	parent=NULL;
	if(tree==NULL)
	{
		printf("tree is empty");
		return tree;
	}
	p=tree;
	while((p!=NULL)&& (p->info!=x))
	{
		parent=p;
		p=((x<p->info)?p->left:p->right);
	}
	if(p==NULL)
	{
		printf("Value not found");
		return tree;
	}
	if(p->left==NULL && p->right==NULL)
	q=NULL;
	else if(p->left==NULL)
	q=p->right;
	else if(p->right==NULL)
	q=p->left;
	else{
		parentsuc=p;
		suc=p->right;
		while(suc->left!=NULL)
		{
			parentsuc=suc;
			suc=suc->left;
		}
		if(p==parentsuc)
		suc->left=p->left;
		else{
			suc->left=p->left;
			parentsuc->left=suc->right;
			suc->right=p->right;
		}
		q=suc;
	}
	if(parent==NULL)
	{
		tree=q;
		}else if(parent->left==NULL)
		parent->left=q;
		else
		parent->right=q;
		free(p);
		return tree;	
}
