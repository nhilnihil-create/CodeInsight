#include<stdio.h>
#include<string.h>

int main(){
  char A[12],B[12],C[12];
  scanf("%s%s%s",A,B,C);
  if(A[strlen(A)-1] == B[0] && B[strlen(B)-1] == C[0])
    printf("YES\n");
  else printf("NO\n");
}