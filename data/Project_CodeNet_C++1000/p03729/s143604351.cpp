#include<stdio.h>
#include<string.h>
int main(void){
 int x,y,z;
 char A[100],B[100],C[100];
 scanf("%s%s%s",A,B,C);
 x=strlen(A);
 y=strlen(B);
 z=strlen(C);
 if(A[x-1]==B[0] && B[y-1]==C[0])
  printf("YES\n");
  else
   printf("NO\n");
return 0;
}
