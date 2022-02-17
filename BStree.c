//construct binary search tree and search element from that tree.
#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	struct node *right;
	int data;

};


void insert(struct node** t,int val)
{
struct node *temp=NULL;
	if((*t)==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->right=NULL;
		temp->left=NULL;
		temp->data=val;
		*t=temp;
		return;
	
	}
	if(val<(*t)->data)
	{
		insert(&(*t)->left,val);
	}
	else 
	{
		insert(&(*t)->right,val);
	}


}

struct node* search(struct node **t,int value)
{
	
	if((*t)==NULL)
		return NULL;
	if(value>(*t)->data)
		search(&((*t)->right),value);
	else if (value<(*t)->data)
	 	 search(&((*t)->left),value);
	else if((*t)->data==value)
		return *t;
	

}

void inord(struct node *t)
{
	if(t==NULL)
		return;
	
	inord(t->left);
		
	printf("%d ",t->data);
		
	inord(t->right);
}


void main()
{
	 int arr[10]={50,25,75,22,40,60,80,90,15,30};
	 int i,n;
 
 
	 struct node* t=NULL;
	 
	 for (i=0;i<10;i++)
		 insert(&t,arr[i]);
		 
	 printf("inorder node:\n");
	 inord(t);
	 printf("\nenter a value which you want to search: ");
	 scanf("%d",&n);
	 struct node *temp=search(&t,n);
	 if(temp)
	 	printf("%d is exist in tree.",n);
	 else
	 	printf("%d is not exist in tree.",n);

}



















