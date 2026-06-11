#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
  int N,A,res=0;

  scanf("%d",&N);

  scanf("%d",&A);

  res=(N*N)-A;

  printf("%d",res);

  return 0;
}
