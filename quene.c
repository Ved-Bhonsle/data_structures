#include <stdio.h>
#include <string.h>

void enquene(char [],int*,int*,int,char);
char dequene(char [],int*,int*);

char quene[30];
int front = 0,rear = 0;

int main()
{
	int choice,n,process = 1;
	char element;

	printf("Enter size of quene:");
	scanf("%d",&n);
	
	while(process != 0){
		printf("Enquene or dequene?");
		scanf("%d",&choice);
		
		if(choice){
			printf("Enter element:");
			scanf("\n%c",&element);
			enquene(quene,&front,&rear,n,element);
		}
		else { dequene(quene,&front,&rear); }
		
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
