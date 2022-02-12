#include <stdio.h>
#include <stdlib.h>

struct node 
{
int info;
struct node *rptr;
struct node *lptr;
};

void display(struct node *first)
{
	struct node *save;  
    	save = first;
	if(save == NULL) { printf("Nothing to print!\n"); }     
	else {   
	 	while (save != NULL)  
    		{  
       			printf("%d ",save->info);  
       			save = save->rptr;  
    		}  
	}

}

struct node* dou_del(struct node *l,struct node *r,struct node *address) //This function deletes node whose address is given
{
	if(r == NULL) //check if list is empty
	{
		printf("Underflow");
		return l;
	}
	//delete node
	if(l == r) // if there is a single node in list
	{
		l = r = NULL;
	}
	else if(address == l) //if the node to delete is the leftmost node
	{
		l = address->rptr;
		l->lptr = NULL;
	}
	else if(address == r) //if the node to delete is the rightmost node
	{
		r = address->lptr;
		r->rptr = NULL;
	}
	else //if the node is in the middle
	{
		address->lptr->rptr = address->rptr,
		address->rptr->lptr = address->lptr;
	}
	free(address);
	return l;
}

struct node* dou_ins(struct node *l,struct node *r,struct node *address, int x) //This function adds a node to the left of the specified address
{
	//create new node
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));

	new->info = x;

	//check if insertion is in a empty list
	if(r == NULL)
	{
		new->lptr = NULL;
		new->rptr = NULL;
		l = r = new;
		return l;
	}

	//check if insertion is to the left most node
	if(address == l)
	{
		new->lptr = NULL;
		new->rptr = address;
		address->lptr = new;
		l = new;
		return l;
	}

	// if insertion is in middle
	new->lptr = address->lptr;
	address->lptr = new;
	new->rptr = address;
	new->lptr->rptr = new;
	return l;
}

void main()
{
struct node *first,*second,*third,*fourth;

first = (struct node*)malloc(sizeof(struct node));
second = (struct node*)malloc(sizeof(struct node));
third = (struct node*)malloc(sizeof(struct node));
fourth = (struct node*)malloc(sizeof(struct node));

first->info = 1;
first->lptr = NULL;
first->rptr = second;

second->info = 2;
second->lptr = first;
second->rptr = third;

third->info = 3;
third->lptr = second;
third->rptr = fourth;

fourth->info = 4;
fourth->lptr = third;
fourth->rptr = NULL;

first = dou_ins(first,third,second,30);
display(first);
printf("\n");

first = dou_ins(first,fourth,fourth,50);
display(first);
printf("\n");

first = dou_del(first,fourth,fourth);
display(first);
}
