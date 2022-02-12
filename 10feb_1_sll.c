#include <stdio.h>
#include <stdlib.h>

struct node
{
int info;
struct node *link;
};

int count_nodes(struct node *first)
{
	int c = 0;
	struct node *save;
	save = first;
	if(save == NULL) { return c; }
	else
	{
	while(save != NULL) { 
		c++;
		save = save->link; 
	}
	return c;
	}
}

void display(struct node *first)
{
	struct node *save;  
    	save = first;
	if(save == NULL) { printf("Nothing to print!\n"); }     
	else {   
	 	while (save != NULL)  
    		{  
       			printf("%d ",save->info);  
       			save = save->link;  
    		}  
	}

}

struct node* insord(int x,struct node *first)
{
	struct node *new,*save;
	new = (struct node*)malloc(sizeof(struct node));

	if(new == NULL)
	{
		printf("Avalability Stack Underflow");
		return first;
	}

	new->info = x;

	if(first == NULL)
	{
		new->link = NULL;
		return new;
	}

	if(new->info <= first->info)
	{
		new->link = first;
		return new;
	}
	else
	{
		save = first;
		while(save->link != NULL && new->info >= save->link->info)
		{
			save = save->link;
		}
		new->link = save->link;
		save->link = new;
		return first;
	}


}


struct node* insend(int x,struct node *first)
{
	struct node *new,*save;
	new = (struct node*)malloc(sizeof(struct node));

	if(new == NULL)
	{
		printf("Avalability Stack Underflow");
		return first;
	}

	new->info = x;
	new->link = NULL;

	if(first == NULL)
	{
		return new;
	}
	else
	{
		save = first;
		while(save->link != NULL)
		{
			save = save->link; 
		}
		save->link = new;
		return first;
	}
}

struct node* insert(int x,struct node *first)
{
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));

	if(new == NULL)
	{
		printf("Overflow\n");
		return first;
	}
	else
	{
		new->info = x;
		new->link = first;
		return new;
	}
}

struct node* delete(struct node* x,struct node *first)
{
	struct node *save,*pred;
	//pred = (struct node*)malloc(sizeof(struct node));

	//check if list is empty
	if(first == NULL)
	{
		printf("Underflow");
		return first;
	}
	save = first;
	while((save != x) && (save->link != NULL))
	{
		pred = save; //update predecessor marker
		save = save->link; //move to next node
	}
	if(save != x) //check whether the list has ended
	{
		printf("Node not found");
		return first;
	}
	if(x == first) // 
	{
		first = first->link;
		return first;
	}
	else
	{
		pred->link = x->link;
		return first;
	}
	free(x);
}

struct node* copy(struct node* head)
{
    struct node* current = head;    // used to iterate over the original list
    struct node* newList = NULL;    // head of the new list
    struct node* tail = NULL;       // point to the last node in a new list
 
    while (current != NULL)
    {
        // special case for the first new node
        if (newList == NULL)
        {
            newList = (struct node*)malloc(sizeof(struct node));
            newList->info = current->info;
            newList->link = NULL;
            tail = newList;
        }
        else {
            tail->link = (struct node*)malloc(sizeof(struct node));
            tail = tail->link;
            tail->info = current->info;
            tail->link = NULL;
        }
        current = current->link;
    } 
    return newList;
}


void main()
{
int x;

struct node *first,*second,*third,*llist2;

first = (struct node*)malloc(sizeof(struct node));
second = (struct node*)malloc(sizeof(struct node));
third = (struct node*)malloc(sizeof(struct node));


printf("Enter value:");
scanf("%d",&first->info);
first->link = second;

printf("Enter value:");
scanf("%d",&second->info);
second->link = third;

printf("Enter value:");
scanf("%d",&third->info);
third->link = NULL;

display(first);
//printf("\nNumber of nodes: %d\n",count_nodes(first));

printf("Enter value to add at first:");
scanf("%d",&x);
first = insert(x,first);
display(first);
printf("\nNumber of nodes: %d\n",count_nodes(first));

printf("Enter value to add at last");
scanf("%d",&x);
first = insend(x,first);
display(first);
printf("\nNumber of nodes: %d\n",count_nodes(first));

printf("Enter value in middle:");
scanf("%d",&x);
first = insord(x,first);
display(first);
printf("\nNumber of nodes: %d\n",count_nodes(first));

first = delete(second,first);
display(first);


llist2 = copy(first);
printf("\nCopied linked list:\n");
display(llist2);


}
