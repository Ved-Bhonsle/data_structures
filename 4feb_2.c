#include <stdio.h>
#include <stdlib.h>

int main()
{
int row,col,ba,i,j,choice,c,add;

c = sizeof(int);
printf("Enter rows and cols:");
scanf("%d %d",&row,&col);
printf("Enter base address:");
scanf("%d",&ba);

enter_i_j:
printf("Enter i and j:");
scanf("%d %d",&i,&j);
printf("Enter 1 for column major and 0 for row major:");
scanf("%d",&choice);

if(i>row || j<col){ 
printf("Index out of range\n");
goto enter_i_j;
}

if(choice) { add = ba + ((j-1)*row + (i-1))*c; }
else { add = ba + ((i-1)*col + (j-1))*c; }

printf("Address of a[%d][%d]:%d",row,col,add);

return 0;
}
