#include <stdio.h>
#include <string.h>

char cqdelete(int*,int*,char [],int);
void cqinsert(int*,int*,char [],int,char);

char cquene[30];
int front = 0,rear = 0;

int main()
{
	int choice,n,process = 1;
	char element;

	printf("Enter size of quene:");
	scanf("%d",&n);
	
	while(process != 0){
		printf("Display_quene(0) or cqinsert(1) or cqdelete(2)?");
		scanf("%d",&choice);

		switch(choice)
		{
			case 0:
				for(int i = 0;i < n + 1; i++) { printf("%c " ,cquene[i]); }
				break;
			case 1:
				printf("Enter element:");
				scanf("\n%c",&element);
				cqinsert(&front,&rear,cquene,n,element);
				break;
			case 2:
				cqdelete(&front,&rear,cquene,n);
				break;

		}		
		printf("\nWant to continue?");
		scanf("%d",&process);
	}
}


void cqinsert(int *f,int *r,char q[],int size,char element)
{
	if(*r == size) { *r = 1; }
	else { *r = *r + 1; }

	if(*f == *r) { 
	printf("Quene Overflow");
	return; 
	}
	else
	{ 
		q[*r] = element;
		printf("\n%c added in circular quene",q[*r]);
		if( *f == 0) { 
			*f = 1;
			return;
		}
	}
}

char cqdelete(int *f,int *r,char q[],int size)
{
	char y;

	//checking for underflow
	if(*f == 0) { 
		printf("Quene Underflow");
		return '0';
	}
	else
	{
		//delete element
		y = q[*f];
		printf("\n%c removed from circular quene",y);
	
		//check if quene is now empty or not
		if(*f == *r) {
			printf("Hello\n"); 
			*f = 0;
			*r = 0;
			return y; 
		}
		else
		{	
			// increment front pointer
			if(*f == size) { *f = 1; }
			else { *f = *f + 1; }
			return y;
		}
	}
}
