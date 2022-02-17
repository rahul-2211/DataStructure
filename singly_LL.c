#include<stdio.h>
#include<stdlib.h>
int count();


struct node
{
int info;
struct node *link;
};

struct node *start=NULL;
struct node *copy=NULL;

struct node* createNode()
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	return n;

}
void copyNode()
{
	struct node *t,*p,*c,*r;
	p=start;
	
	
		
		int x=count();
		if(p->link==NULL)
		{
			c=createNode();
			c->info=p->info;
			c->link=NULL;
			printf("%d\t",c->info);
		
		}
		else
		{
			while(x!=-1)
				{
				
					struct node *temp,*t,*p;
					p=start;
					temp=createNode();
					//temp->info=p->info;
					//p=p->link;
		 			
		 			if(copy==NULL)
	  				    copy=temp;
	
					else
					{
					  t=copy;
					 
					  while(t->link!=NULL)
					    t=t->link;
					  t->link=temp;
					}
									
					
				
				x--;
				}
				
		}
		
         
	 
	r=copy;
	 while(r->link!=NULL)
	 {
	 	r->info=p->info;
	 	p=p->link;
	 	r=r->link;
	 
	 }
	 
	printf("copied elements are:\n");
	 while(copy->link!=NULL)
	{
	    printf("%d\t",copy->info);
	    copy=copy->link;
	}
	 
	


}

///insert at the end
void insertNode()
{
	struct node *temp,*t;
	temp=createNode();
	printf("enter info: \n");
	scanf("%d",&temp->info);
	if(start==NULL)
	  start=temp;
	else
	{
	  t=start;
	  while(t->link!=NULL)
	    t=t->link;
	  t->link=temp;
	}
}
///insert at the end
void insertfirst()
{
	struct node *temp,*t;
	temp=createNode();
	printf("enter info:\n");
	scanf("%d",&temp->info);
	if(start==NULL)
	  start=temp;
	else
	{
	  t=start;
	  temp->link=t;
	  start=temp;
	}
	
	


}

struct node* insord()
{
 int val;
 struct node *temp,*t;
 temp=createNode();
 t=start;
 printf("enter value:\n");
 scanf("%d",&val);
 temp->info=val;
 while(t->link!=NULL && (temp->info)>=(t->link->info))
 {
 	
 	t=t->link;
 
 }
 		temp->link=t->link;
 		t->link=temp;
		return start;
 		


}

//delete first node
void deleteFnode()
{
	struct node *r;
	if(start==NULL)
	  printf("list is empty\n");
	r=start;
	start=start->link;
	free(r);
}

struct node* deleteNode()
{
	int val;
	printf("enter node-info which you want to delete:\n");
	scanf("%d",&val);
	struct node *t,*p=NULL;
	t=start;
	while(t->link!=NULL && t->link->info!=val)
	{
		t=t->link;
		//p=t;
	}
	p=t;
	t=t->link;
	p->link=t->link;
	free(t);
	return (start);


}

//print LL

void display()
{
	struct node *t;
	t=start;
	if(start==NULL)
	  printf("list is empty\n");
	while(t!=NULL)
	{
	    printf("%d\t",t->info);
	    t=t->link;
	}

}

int count()
{
	int c=0;
	struct node *t;
	t=start;
	if(start==NULL)
	  printf("list is empty\n");
	while(t!=NULL)
	{
	   c++;
	    t=t->link;
	}
	//printf("total node is %d:",c);
	return c;

}


int main()
{

	int ch;
	while(1)
	{
	printf("\n1.intsertL-node\n2.intsertF-node\n3.delete-node\n4.display-list\n5.count\n6.insord\n7.copy-Node\n8.delete-Node-User\n9.Quit\n");
	printf("enter choice:\n");
	scanf("%d",&ch);

	switch(ch)
	{
	case 1: insertNode();
	break;
	
	case 2: insertfirst();
	break;
	
	case 3: deleteFnode();
	break;
	
	case 4: display();
	break;
	
	case 5:printf(" total elements are : %d",count());
	break;
	
	case 6: insord();
	break;
	
	case 7: copyNode();
	break;
	
	case 8: deleteNode();
	break;
	
	case 9: printf("\nthank you");
	exit(1);
	
	
	}
}
} 
