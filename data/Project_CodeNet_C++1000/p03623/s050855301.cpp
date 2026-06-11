#include<stdio.h>
int main(void)
{
  int x,a,b;
  int c,d;
  
  scanf("%d",&x);
  scanf("%d",&a);
  scanf("%d",&b);
  
  c=x-a;
  d=x-b;
  if(c<0)
    c*=(-1);
  if(d<0)
    d*=(-1);
  
  if(c<d)
    printf("A");
  else
    printf("B");
  return 0;
}