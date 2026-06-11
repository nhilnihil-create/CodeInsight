#include <stdio.h>

int main(void)
{
  int X,A,B;
  scanf("%d",&X);
  scanf("%d",&A);
  scanf("%d",&B);
  
  if(A>=B)
    printf("delicious");
  else if(A+X>=B)
    printf("safe");
  else
    printf("dangerous");
  
  return 0;
}