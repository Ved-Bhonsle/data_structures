/*
Binary search tree is a data structure that quickly allows us to maintain a sorted list of numbers.

It is called a binary tree because each tree node has a maximum of two children.
It is called a search tree because it can be used to search for the presence of a number in O(log(n)) time.
The properties that separate a binary search tree from a regular binary tree is

1] All nodes of left subtree are less than the root node
2] All nodes of right subtree are more than the root node
3] Both subtrees of each node are also BSTs i.e. they have the above two properties
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *lptr;
struct node *rptr;
};

struct node *delete(struct node *root, int key) 
{
	if (root == NULL)  { return root; }

 	if (key < root->data) { root->lptr = delete(root->lptr, key); }
  	else if (key > root->data) { root->rptr = delete(root->rptr, key); }
	else {
		if (root->lptr == NULL) 
		{
	                struct node *temp = root->rptr;
	       	        free(root);
			return temp;
		} 
		else if (root->rptr == NULL) 
		{
	      		struct node *temp = root->lptr;
	      		free(root);
	      		return temp;
	    	}
		else {
			struct node *current = root->rptr;
	  		while (current && current->lptr != NULL) { current = current->lptr; }

			root->data = current->data;
			root->rptr = delete(root->rptr, current->data);
		}		
	}
	return root;
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
		printf("%d ",tree->data);
		if(tree->rptr != NULL)
		{
			inorder(tree->rptr);
		}
	}
}


struct node *insert(int x, struct node *root)
{

	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));

    	if(root == NULL)
	{
		new->data = x;
		new->lptr = NULL;
		new->rptr = NULL;	
		return new;
	}
    	if(root->data < x)
	{
        	root->rptr = insert(x,root->rptr);
	}
    	else if(root->data > x)
	{
        	root->lptr = insert(x,root->lptr);
	} 
   	return root;
}

void main()
{
	int i,num1,num2;

	struct node *first,*tree;

	first = NULL;
	tree = first;

	for(i = 0;i<10;i++)
	{
		printf("Enter element %d:",i + 1);
		scanf("%d",&num1);
		tree = insert(num1,tree);
	}

	inorder(tree);

	printf("\nEnter element that you wnat to delete:");
	scanf("%d",&num2);
	delete(tree,num2);

	inorder(tree);
}
