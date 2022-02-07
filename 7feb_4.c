#include <stdio.h>
#include <string.h>

void push(char [],int*,char,int);
char pop(char [],int*);

int main()
{
char str[20],x;
int l,i = 0,a_count = 0,b_count = 0,top = 0;

printf("Enter string:");
scanf("%s",str);

l = strlen(str);

char stack[l+1];

push(stack,&top,'e',l+1);

while(str[i] != '\0'){
	//push elements in the stack
	push(stack,&top,str[i],l+1);
	i++;
}

while(1)
{
x = pop(stack,&top);
if(x == 'a') { a_count++; }
else if(x == 'b') { b_count++; }
else { break; }
}

if(a_count == b_count) { printf("Success\n"); }
else {printf("Fail\n");}

return 0;
}

//PUSH FUNCTION
void push(char s[],int *top,char element,int size)
{
	if(*top < size) {
		*top = *top + 1;
		s[*top] = element;
		//printf("\nPushed %c in stack.\n",s[*top]);
		//return s[*top];
	}
	else {
		printf("\nStack Overflow\n");
		//return NULL;
	}
}

//POP FUNCTION
char pop(char s[],int *top) {
	if(*top == 0) {
		printf("\nStack Underflow\n");
		return 'Q';
	}
	else {
		*top = *top - 1;
		//printf("\nTop in stack is %c\n",s[*top]);
		return s[*top + 1];
	}
}
