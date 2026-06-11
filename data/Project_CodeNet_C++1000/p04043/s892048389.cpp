#include <stdio.h>
int main()
{
  int a,b,c,A=0,B=0;
  scanf("%d %d %d",&a,&b,&c);
  if(a==7)A++;
  if(b==7)A++;
  if(c==7)A++;
  if(a==5)B++;
  if(b==5)B++;
  if(c==5)B++;
  if(A==1&&B==2)
  {printf("YES");}
  else printf("NO");
  return 0;
}