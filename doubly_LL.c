#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	struct node *right;
	int info;

};

void addAtbeg(struct node **s,int data)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->info=data;
	p->left=NULL;
	p->right=*s;
	*s=p;
}

void addAtend(struct node **s,int data)
{
	struct node *p,*t;
	p=(struct node*)malloc(sizeof(struct node));
	p->info=data;
	p->right=NULL;
	
	if(*s==NULL)
		{
		p->left=NULL;
		*s=p;
		}
	else
		t=*s;
		while(t->right!=NULL)
			t=t->right;
		p->left=t;
		t->right=p;

}

int delFnode(struct node **s)
{
	struct node *t;
	if(*s==NULL)
		return (0);
	else{
		t=*s;
		*s=(*s)->right;
		(*s)->left=NULL;
		free(t);
		return 1;
	    }
}

int delLnode(struct node **s)
{
	struct node *t;
	if(*s==NULL)
		return (0);
	t=*s;
	while(t->right!=NULL)
		t=t->right;
	if((*s)->right==NULL)
		{*s=NULL;}
	else
		{t->left->right=NULL;}
	free(t);
	return 1;

}

void display(struct node **s)
{
struct node *t;
	if(*s==NULL)
		printf("list is empty\n");
	else
		t=*s;
		while(t!=NULL)
		{
			printf("%d\n",t->info);
			t=t->right;
		}
}

int main()
{
	struct node *start=NULL;
	addAtbeg(&start,10);
	addAtbeg(&start,30);
	addAtend(&start,20);
	printf("display before delete:\n");
	display(&start);
	printf("delete first node:\n");
	delFnode(&start);
	display(&start);
	printf("delete last node:\n");
	delLnode(&start);
	display(&start);

}





