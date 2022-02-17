#include<stdio.h>
#include<stdlib.h>
void display();

struct node
{
	int info;
	struct node *link;
};


void addtoempty();
void addatbeg();
void addatend();
void addafter();
struct node* del(struct node*);

struct node *last=NULL;

struct node* createNode()
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	return n;

}


//print LL

void display()
{
	struct node *t;
	t=last->link;
	if(last==NULL)
	  printf("list is empty\n");
	do
	{
	    printf("%d\t",t->info);
	    t=t->link;
	}while(t!=last->link);

}

void addtoempty()
{
	struct node *temp;
	int value;
	printf("enter info: \n");
	scanf("%d",&value);
	temp=createNode();
	temp->info=value;
	last=temp;
	last->link=last;
	//return last;
	
}

void addatbeg()
{
	struct node *n;
	int value;
	printf("enter info: \n");
	scanf("%d",&value);
	n=createNode();
	n->info=value;
	n->link=last->link;
	last->link=n;
	//return(last);
}


void addatend()
{
	struct node *t;
	int value;
	printf("enter info: \n");
	scanf("%d",&value);
	t=createNode();
	t->info=value;
	t->link=last->link;
	last->link=t;
	last=t;
	//return (last);

}

void addafter()
{
	
	     	int value,item;
		printf("enter item: \n");
		scanf("%d",&item);
		printf("enter info: \n");
		scanf("%d",&value);
		struct node *t,*n;
	     	t=last->link;
		
	do{
	     if(t->info==item)
	     {
		n=createNode();
		n->info=value;
	     	n->link=t->link;
	     	t->link=n; 
	     	if(t==last)
	     	  last=n;
	     	  
       	//return (last);
	     }
	     t=t->link;
	
	}while(t!=last->link);
	
}

struct node* del(struct node* last)

{
	struct node *t,*n;
	int value;
	printf("enter item: \n");
	scanf("%d",&value);
	if(last==NULL)
	  printf("list is empty\n");
	  return(last);
	if(last==last->link && last->info==value)
		t=last;
		last=NULL;
		free(t);
		return (last);
	if(last->link->info==value)
		t=last->link;
		last->link=t->link;
		free(t);
		return (last);
	
	n=last->link;
	while(n->link!=last)
	{
	if(n->link->info==value)
		t=n->link;
		n->link=t->link;
		free(t);
		return (last);
	n=n->link;
	}
	
	if(last->info==value)
		t=last;
		n->link=last->link;
		last=n;
		free(t);
		return(last);
	printf("%d is not in list\n",value);
	return (last);
}





int main()
{

	int ch;
	while(1)
	{
	printf("\n1.addtoempty\n2.addatbeg\n3.addatend\n4.addafter\n5.delete\n6.display\n7.Quit");
	printf("\nenter choice: ");
	scanf("%d",&ch);

	switch(ch)
	{
	case 1:
	addtoempty();
	break;
	
	case 2:
	addatbeg();
	break;
	
	case 3: 
	addatend();
	break;
	
	case 4: 
	addafter();
	break;
	
	case 5: 
	del(last);
	break;
	
	case 6:
	display();
	break;
	
	case 7: printf("\nthank you.");
	exit(1);
	break;	
	
	}
}
}


