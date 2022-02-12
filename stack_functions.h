void push(int s[],int *top,int num,int size)
{
	if(*top < size) {
		*top = *top + 1;
		s[*top] = num;
		}
	else 	{ printf("Stack Overflow\n"); }
}

//POP FUNCTION
int pop(int s[],int *top)
{
	if (*top == 0) {
		printf("Stack Underflow");
		return -1;
	}
	else { 
		*top = *top - 1;
		//printf("\nTop is %d\n",s[*top]);
		return s[*top + 1];
	}
}

// PEEP FUNCTION
int peep(int s[],int *top,int index)
{
	if (*top - index + 1 <= 0){
		printf("Stack Underflow");
		return -1;
	}
	else { return s[*top - index + 1]; }
}

//CHANGE FUNCTION
void change(int s[],int *top,int index,int value)
{
if (*top - index + 1 <= 0) { printf("Stack Underflow"); }
else { s[*top + index - 1] = value; }
}
