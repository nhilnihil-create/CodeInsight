#include <stdio.h>

int main(void)
{
  int A,B;
  scanf("%d",&A);
  scanf("%d",&B);
  if(A%3 == 0 || B%3 == 0 || (A+B)%3 == 0)
    printf("Possible");
  else
    printf("Impossible");
  
  return 0;
}