#include <bits/stdc++.h>

int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  if(a+b<24)
      printf("%d",a+b);
  
  else
  {
    int ans=24-a;
    b-=ans;
    printf("%d",b);
  }
}