#include <stdio.h>
#include <stdlib.h>

struct node
{
char data;
struct node *lptr;
struct node *rptr;
};

void preorder(struct node *tree)
{

	struct node *t;
	if(tree == NULL)
	{
		printf("Empty Tree");
		return;
	}
	else
	{
		printf("%c ",tree->data);
		if(tree->lptr != NULL)
		{
			preorder(tree->lptr);
		}
		if(tree->rptr != NULL)
		{
			preorder(tree->rptr);
		}
	}
}

void inorder(struct node *tree)
{
	if(tree == NULL)
	{
		printf("Empty Tree");
	}
	else
	{
		if(tree->lptr != NULL)
		{
			inorder(tree->lptr);
		}
		printf("%c ",tree->data);
		if(tree->rptr != NULL)
		{
			inorder(tree->rptr);
		}
	}
}

void postorder(struct node *tree)
{
	if(tree == NULL)
	{
		printf("Empty Tree");
	}
	else
	{
		if(tree->lptr != NULL)
		{
			postorder(tree->lptr);
		}
		if(tree->rptr != NULL)
		{
			postorder(tree->rptr);
		}
		printf("%c ",tree->data);
	}
}


void main()
{
	struct node *tree,*A,*B,*C,*D,*E,*F,*G;
	A = (struct node*)malloc(sizeof(struct node));
	B = (struct node*)malloc(sizeof(struct node));
	C = (struct node*)malloc(sizeof(struct node));
	D = (struct node*)malloc(sizeof(struct node));
	E = (struct node*)malloc(sizeof(struct node));
	F = (struct node*)malloc(sizeof(struct node));
	G = (struct node*)malloc(sizeof(struct node));

	tree = A;

	A->data = 'a';
	A->lptr = B;
	A->rptr = D;

	B->data = 'b';
	B->lptr = C;
	B->rptr = NULL;

	C->data = 'c';
	C->lptr = NULL;
	C->rptr = NULL;

	D->data = 'd';
	D->lptr = E;
	D->rptr = G;

	E->data = 'e';
	E->lptr = NULL;
	E->rptr = F;

	F->data = 'f';
	F->lptr = NULL;
	F->rptr = NULL;

	G->data = 'g';
	G->lptr = NULL;
	G->rptr = NULL;

	printf("Preorder:");
	preorder(tree);
	printf("\n");

	printf("Inorder:");
	inorder(tree);
	printf("\n");

	printf("Postorder:");
	postorder(tree);
	printf("\n");
}
