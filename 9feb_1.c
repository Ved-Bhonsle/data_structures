#include <stdio.h>
#include <string.h>

char dqdelete_rear(char [],int*,int*);
void dqinsert_front(char [],int*,int*,char,int);
char cqdelete(int*,int*,char [],int);
void cqinsert(int*,int*,char [],int,char);
void enquene(char [],int*,int*,int,char);
char dequene(char [],int*,int*);

char cquene[30];
char dquene[30];
char quene[30];
int front = 0,rear = 0;

int main()
{
	int choice,n,process = 1;
	char element;

	printf("Enter size of quene:");
	scanf("%d",&n);
	
	while(process != 0){
		printf("Display_quene(0) or Enquene(1) or dequene(2) or cqinsert(3) or cqdelete(4) or dqinsert_front(5) or dqdelete_rear(6)?");
		scanf("%d",&choice);

		switch(choice)
		{
			case 0:
				for(int i = 0;i < n + 1; i++) { printf("%c " ,quene[i]); }
				break;
			case 1:
				printf("Enter element:");
				scanf("\n%c",&element);
				enquene(quene,&front,&rear,n,element);
				break;
			case 2:
				dequene(quene,&front,&rear);
				break;
			case 3:
				printf("Enter element:");
				scanf("\n%c",&element);
				cqinsert(&front,&rear,cquene,n,element);
				break;
			case 4:
				cqdelete(&front,&rear,cquene,n);
				break;
			case 5:
				printf("Enter element:");
				scanf("\n%c",&element);
				dqinsert_front(dquene,&front,&rear,element,n);
				break;
			case 6:
				dqdelete_rear(dquene,&front,&rear);
				break;
		}		
		/*
		if(choice){
			printf("Enter element:");
			scanf("\n%c",&element);
			enquene(quene,&front,&rear,n,element);
		}
		else { dequene(quene,&front,&rear); }
		*/
		printf("\nWant to continue?");
		scanf("%d",&process);
	}
}

void enquene(char q[],int *f,int *r,int size,char element)
{
	if(*r >= size) { printf("Quene Overflow"); }
	else{ 
		*r = *r + 1;
		q[*r] = element;
		printf("\n%c added in quene",q[*r]);
		if(*f == 0) { *f = 1; }
	}
}

char dequene(char q[],int *f,int *r)
{
	char y;
	if (*f == 0)
	{
		printf("Quene Underflow");
		return '0';
	}
	y = q[*f];
	printf("\n%c removed from quene",q[*f]);
	if(*f == *r) { *f = *r = 0; }
	else { *f = *f + 1; }
	return y;
	
}

void cqinsert(int *f,int *r,char q[],int size,char element)
{
	if(*r == size) { *r = 1; }
	else { *r = *r + 1; }

	if(*f == *r) { printf("Quene Overflow"); }
	else { 
		q[*r] = element;
		printf("\n%c added in circular quene",q[*r]);
		if( *f == 0) { *f = 1; }
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

	//delete element
	y = q[*f];
	printf("\n%c removed from circular quene",y);
	
	//check if quene is now empty or not
	if(*f == *r) { 
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

void dqinsert_front(char q[],int *f,int *r,char element,int size) 
{
	if(*f == 0) { printf("Empty Quene"); }
	else if (*f == 1) { printf("Quene Overflow"); }
	else {
		*f = *f + 1;
		q[*f] = element;
		printf("\n%c added in dquene",q[*f]);
	}
}

char dqdelete_rear(char q[],int *f,int *r)
{
char y;
	//Check for quene underflow
	if(*r == 0) { printf("Quene Underflow"); }
	else {
		//Delete element
		y = q[*r];
		printf("\n%c removed from dquene",y);
		//Check if quene is empty 
		if(*r == *f){
			*r = 0;
			*f = 0;
		}
		else { *r = *r - 1; }
		return y;
	}

}
