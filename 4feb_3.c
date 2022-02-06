#include <stdio.h>
#include <string.h>

int main()
{
char terms1[10],terms2[10];
int k,a[3][3] = {0},b[3][3] = {0},pwr_xa,pwr_xb,pwr_ya,pwr_yb,i,j,coeff,lt2,lt1;

printf("Enter first polynomial:");
while(terms1[0] != -1){
printf("Enter term:");
scanf("%s",terms1);
printf("Enter coefficient:");
scanf("%d",&coeff);
lt1 = strlen(terms1);
for(k = 0;k<lt1;k++){
if(terms1[k] >= '0' && terms1[k] <= '9') { 
pwr_xa = (int)terms1[k]; 
pwr_ya = 0;
}
a[pwr_xa][pwr_ya] = coeff; 
}
}

printf("Enter second polynomial:");
while(terms2[0] != -1){
printf("Enter term:");
scanf("%s",terms2);
printf("Enter coefficient:");
scanf("%d",&coeff);
lt2 = strlen(terms2);
for(k = 0;k<lt1;k++){
if(terms2[k] >= '0' && terms2[k] <= '9') { 
pwr_xb = (int)terms2[k]; 
pwr_yb = 0;
}
b[pwr_xb][pwr_yb] = coeff; 
}
}

printf("\nMat 1\n");
for(i = 0;i<3;i++){
for(j = 0;j<3;j++) { printf("%d",a[i][j]); }
printf("\n");
}

printf("\nMat 2\n");
for(i = 0;i<3;i++){
for(j = 0;j<3;j++) { printf("%d",b[i][j]); }
printf("\n");
}

return 0;
}

