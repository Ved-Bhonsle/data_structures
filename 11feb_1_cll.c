#include <stdio.h>
#include <stdlib.h>

struct node
{
int info;
struct node *link;
};

void display(struct node *first,struct node *last)
{
	struct node *save;
	if(first == NULL)
	{
		printf("Empty List");
	}
	else
	{
		save = first;
		while(save != NULL)
		{
			if(save == last)
			{
				printf("%d ",save->info);
				return;
			}
			printf("%d ",save->info);
			save = save->link;
		}
	}
}

struct node* cir_delete(struct node *address,struct node *first,struct node *last)
{
	struct node *save,*pred;
	if(first == NULL)
	{
		printf("Empty List");
		return first;
	}
	else
	{
		save = first;
		while((save != address) && (save != last))
		{
			pred = save;
			save = save->link;
		}
		if(save != address)
		{
			printf("Node not found");
			return first;
		}
		if(address == first)
		{
			first = first->link;
			last->link = first;
		}
		else
		{
			pred->link = address->link;
			if(address == last)
			{
				last = pred;
			}
		}
		return first;
	}
}

struct node* cir_ins_ord(int x, struct node *first,struct node *last)
{
	struct node *new,*save,*pred;
	new = (struct node*)malloc(sizeof(struct node));
	new->info = x;

	if(first == NULL)
	{
		new->link = new;
		first = last = new;
		return first;
	}
	else
	{
		if(new->info <= first->info)
		{
			new->link = first;
			last->link = new;
			first = new;
			return first;
		}
		save = first;
		while ((save != last) && (new->info >= save->info))
		{
			pred = save;
			save = save->link;
		}
		new->link = save;
		pred->link = new;
		if(save == last)
		{
			last = new;
		}
		return first;
	}
}

struct node *cir_ins_last(int x, struct node *first,struct node *last)
{
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));
	new->info = x;

	if(first == NULL)
	{
		new->link = new;
		first = last = new;
		return last;
	}
	else
	{
		new->link = first;
		last->link = new;
		last = new;
		return last;
	}
}

struct node *cir_ins_first(int x,struct node *first,struct node *last)
{
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));
	new->info = x;
	
	if(first == NULL)
	{
		new->link = new;
		first = last = new;
		return new;
	}
	else
	{
		new->link = first;
		last->link = new;
		first = new;
		return new;
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

void main()
{
struct node *first,*second,*third,*fourth,*test,*last;

first = (struct node*)malloc(sizeof(struct node));
second = (struct node*)malloc(sizeof(struct node));
third = (struct node*)malloc(sizeof(struct node));
fourth = (struct node*)malloc(sizeof(struct node));

printf("Enter value:");
scanf("%d",&first->info);
first->link = second;

printf("Enter value:");
scanf("%d",&second->info);
second->link = third;

printf("Enter value:");
scanf("%d",&third->info);
third->link = fourth;

printf("Enter value:");
scanf("%d",&fourth->info);
fourth->link = NULL;

display(first,fourth);
printf("\n");

first = cir_ins_first(5,first,fourth);
display(first,fourth);
printf("\n");

last = cir_ins_last(55,first,fourth);
display(first,last);
printf("\n");

first = cir_ins_ord(25,first,last);
display(first,last);
printf("\n");

first = cir_delete(third,first,last);
display(first,last);
printf("\n");
}
