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

struct node *cir_head_ins_after_address(int x, struct node *head, struct node *last, struct node *address)
{
struct node *new,*pred,*save;
new = (struct node*)malloc(sizeof(struct node));
new->info = x;

	if(new == NULL)
	{
		printf("Underflow");
		return head;
	}
else
{
new->link = address->link;
address->link = new;
if(address == last)
{
last = new;
}
return head;
}
}

struct node *cir_head_ins_last(int x, struct node *head, struct node *last)
{
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));
	new->info = x;

	if(new == NULL)
	{
		printf("Underflow");
		return last;
	}
	else {
		new->link = head;
		last->link = new;
		last = new;
		return last;
	}
}

struct node *cir_head_ins_first(int x,struct node *head,struct node *last)
{
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));
	new->info = x;

	if(new == NULL)
	{
		printf("Underflow");
		return head;
	}
	else
	{
		new->link = head->link;
		head->link = new;
		return head;
	}
}

void main()
{
struct node *head,*first,*second,*third,*fourth,*last;

first = (struct node*)malloc(sizeof(struct node));
second = (struct node*)malloc(sizeof(struct node));
third = (struct node*)malloc(sizeof(struct node));
fourth = (struct node*)malloc(sizeof(struct node));

head->link = first;

first->info = 10;
first->link = second;

second->info = 20;
second->link = third;

third->info = 30;
third->link = fourth;

fourth->info = 40;
fourth->link = head;

last = fourth;

display(head->link,last);
printf("\n");

head = cir_head_ins_first(5,head,last);
display(head->link,last);
printf("\n");

last = cir_head_ins_last(50,head,last);
display(head->link,last);
printf("\n");

head = cir_head_ins_after_address(35,head,last,third);
display(head->link,last);
printf("\n");

}
