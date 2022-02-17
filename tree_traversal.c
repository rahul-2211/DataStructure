#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node *left;
	struct node *right;
};


void preord(struct node *t)
{
	if(t==NULL)
		return;
	
	printf("%c ",t->data);
		
	preord(t->left);
		
	preord(t->right);
	
	

} 

void inord(struct node *t)
{
	if(t==NULL)
		return;
	
	inord(t->left);
		
	printf("%c ",t->data);
		
	inord(t->right);
	
	

} 
void postord(struct node *t)
{
	if(t==NULL)
		return;
	
		
	postord(t->left);
		
	postord(t->right);
	
	printf("%c ",t->data);
	

} 

int main()
{
	struct node *a,*b,*c,*d,*e,*f,*g,*t;
	a=(struct node *)malloc(sizeof(struct node));
	b=(struct node *)malloc(sizeof(struct node));
	c=(struct node *)malloc(sizeof(struct node));
	d=(struct node *)malloc(sizeof(struct node));
	e=(struct node *)malloc(sizeof(struct node));
	f=(struct node *)malloc(sizeof(struct node));
	g=(struct node *)malloc(sizeof(struct node));
	t=a;
	
	
	a->data='A';
	a->left=b;
	a->right=d;
	
	b->data='B';
	b->left=c;
	b->right=NULL;
	
	c->data='C';
	c->left=NULL;
	c->right=NULL;
	
	d->data='D';
	d->left=e;
	d->right=g;
	
	e->data='E';
	e->left=NULL;
	e->right=f;
	
	f->data='F';
	f->left=NULL;
	f->right=NULL;
	
	g->data='G';
	g->left=NULL;
	g->right=NULL;
	
	
	printf("pre-order:\n");
	preord(t);
	printf("\nin-order:\n");
	inord(t);
	printf("\npost-order:\n");
	postord(t);

}











