#include <stdio.h>
#include <string.h>

char dqdelete_rear(char [],int*,int*);
void dqinsert_front(char [],int*,int*,char,int);
void enquene(char [],int*,int*,int,char);
char dequene(char [],int*,int*);

char dquene[30];
int front = 0,rear = 0;

int main()
{
	int choice,n,process = 1;
	char element;

	printf("Enter size of quene:");
	scanf("%d",&n);
	
	while(process != 0){
		printf("Display_quene(0) or enquene(1) or dequene(2) or dqinsert_front(3) or dqdelete_rear(4)?");
		scanf("%d",&choice);

		switch(choice)
		{
			case 0:
				for(int i = 0;i < n + 1; i++) { printf("%c " ,dquene[i]); }
				break;
			case 1:
				printf("Enter element:");
				scanf("\n%c",&element);
				enquene(dquene,&front,&rear,n,element);
				break;
			case 2:
				dequene(dquene,&front,&rear);
				break;
			case 3:
				printf("Enter element:");
				scanf("\n%c",&element);
				dqinsert_front(dquene,&front,&rear,element,n);
				break;
			case 4:
				dqdelete_rear(dquene,&front,&rear);
				break;
		}
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
