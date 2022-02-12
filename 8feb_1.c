/*

Turn An Infix argument into Postfix 

*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

void push(char [],int*,char,int);
char pop(char [],int*);
void convert(char []);
int pre(char);

char stack[30];
int top = 0;

int main()
{
char str[20];

printf("Enter string:");
scanf("%s",str);

convert(str);

return 0;
}

void push(char s[],int *top,char element,int size)
{
	if(*top > size) { printf("Stack Overflow"); }
	else { 
		*top = *top + 1;
		s[*top] = element;
	}
}

char pop(char s[],int *top)
{
	if(*top == 0) { 
		printf("Stack Underflow");
		return '0';
	}
	else {
		*top = *top - 1;
		return s[*top + 1];
	}
}

void convert(char s[])
{
	int i = 0,j = 0;
	char output[20];
	while(s[i] != '\0'){
		if(isalpha(s[i])){ 
			output[j] = s[i];
			j++; 
		}
		else if (s[i] == '(') { push(stack,&top,s[i],30); }
		else if (s[i] == ')') 
		{ 
			while(pop(stack,&top) != '(')
			{
				output[j] = pop(stack,&top);
				j++;
			}
		}
		else {
			while(pre(s[i]) <= pre(stack[top]))
			{
				output[j] = pop(stack,&top);
				j++;
			}
			push(stack,&top,s[i],30);
		}
		i++;
	}
	while(top != 0)
	{ 
		output[j] = pop(stack,&top);
		j++;
	}

	for(int k = 0;k < strlen(output);k++){ printf("%c",output[k]); }
}

int pre(char x)
{
	switch(x)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '^':
		return 3;
	}
}
