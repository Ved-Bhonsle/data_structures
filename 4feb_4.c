#include <stdio.h>

int main()
{
int n = 0,r,c,i,j;

printf("Enter rows:");
scanf("%d",&r);
printf("Enter columns:");
scanf("%d",&c);

int a[r][c],b[3][20];

printf("Enter elements of the matrix:\n");
for(i = 0;i<r;i++){
for(j = 0;j<c;j++) { scanf("%d",&a[i][j]); }
}

for(i = 0;i<r;i++){
for(j = 0;j<c;j++) {
if(a[i][j] != 0){
b[2][n] = a[i][j];
b[1][n] = j+1;
b[0][n] = i+1;
n++;
}
}
}

printf("\nEntered matrix is:\n");
for(i = 0;i<r;i++){
for(j = 0;j<c;j++) { printf("%d\t",a[i][j]); }
printf("\n");
}

printf("\nSparce matrix:\n");
for(i = 0;i<3;i++){
for(j = 0;j<n;j++) { printf("%d\t",b[i][j]); }
printf("\n");
}

return 0;
}
