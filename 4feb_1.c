#include <stdio.h>
#include <stdlib.h>

int main()
{
int n;

printf("Enter the numer of elements in array:");
scanf("%d",&n);

int a[n],ba,i,c,add;

c = sizeof(int);
printf("Enter address of a[0]:");
scanf("%d",&ba);

enter_i:
printf("\nEnter the i:");
scanf("%d",&i);

printf("Address of a[0]: %d\n",ba);

if(i<n){
add = ba + (c*(i-1));
printf("Address of ith element is: %d",add); 
}
else{
printf("index i out of range");
goto enter_i;}
return 0;
}
