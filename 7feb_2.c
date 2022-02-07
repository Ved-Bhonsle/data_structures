#include <stdio.h>
#include "stack_functions.h"

int main()
{
int top = 0,k,n,x,i,z,choice,index,value;

printf("Enter size of stack:");
scanf("%d",&n);
	
int stack[n+1];

while(1)
	{
	printf("\nEnter number:");
	scanf("%d",&x);
	if(push(stack,&top,x,n) == 0) { break; }
	else { printf("Element Added Successfully"); }
	}

printf("Which function do you want do do?");
scanf("%d",&k);
switch(k)
{
case 1:
	printf("\nEnter number:");
	scanf("%d",&x);
	if(push(stack,&top,x,n) == 0) { break; }
	else { printf("Element Added Successfully"); }
 	break;
case 2:
	z = pop(stack,&top);
	if (z != -1) { printf("Poped element : %d\n",z); }
	break;
case 3:
	printf("Enter index in stack to peep:");
	scanf("%d",&index);
	printf("Element at %d is %d",index,peep(stack,&top,index));
	break;
case 4:
	printf("Enter index of element that you want to change:");
	scanf("%d",&index);
	printf("Enter element value:");
	scanf("%d",&value);
	printf("After change,element at %d is %d",index,change(stack,&top,index,value));
	break;
default:
	for (i = n;i>0;i--){
	printf("%d ",stack[i]);
	}
}

return 0;
}

