#include <stdio.h>
#include <string.h>
#include <ctype.h>

void push(char [],int*,char,int);
char pop(char [],int*);
void solution(char []);

char stack[30];
int top = 0;

int main()
{
char str[30];

printf("Enter string:");
scanf("%s",str);

solution(str);

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

void solution(char s[])
{
	int i = 0,a,b,c;
	char x,d;

	while(s[i] != '\0'){
	if(isdigit(s[i])) { 
		push(stack,&top,s[i],30);
		printf("%c pushed\n",s[i]);
 	}
	else {
		x = s[i];
		b = (int)(pop(stack,&top)) - 48;
		a = (int)(pop(stack,&top)) - 48;
			switch(x)
			{
			case '+':
				c = a + b;
				break;
			case '-':
				c = a - b;
				break;
			case '*':
				c = a*b;
				break;
			case '/':
				c = a/b;
				break;
			}
			d = (char)(c + 48);
			push(stack,&top,d,30);
		}
		i++;
	}
	printf("Answer: %d\n",(int)(pop(stack,&top)) - 48);
}
