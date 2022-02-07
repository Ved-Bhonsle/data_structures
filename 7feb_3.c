#include <string.h>
#include <stdio.h>

void push(char [],int*,char,int);
char pop(char [],int*);

int main()
{
	int j,i,n,l,top = 0,flag = 0,index;
	char str[20],ch,x;

	printf("Enter string:");
	scanf("%s",str);

	l = strlen(str);

	char stack[l+1];

	push(stack,&top,'e',l);

	while(str[i] != 'c') {
		//push elements in the stack
		push(stack,&top,str[i],l);
		i++;
	}

	for(j = 0;j < l;j++) {
		if(str[j] == 'c') { index = j + 1; }
	}

	while(1)
	{
		x = pop(stack,&top);
		if(x == 'e' && str[index] == '\0'){
			//if(flag == 0) { printf("\nPalindrome\n"); }
			break;
		}
		else { 
			if(x != str[index]) {
				flag = 1;
				break;
			}
		}
	index++;
	}

	if(flag == 0) { printf("Palindrome\n"); }
	else { printf("Not a Palindrome\n"); }

	return 0;
}

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
