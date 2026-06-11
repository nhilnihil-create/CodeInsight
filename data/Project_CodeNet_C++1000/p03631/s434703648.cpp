#include <iostream>

int pal(int n)
{
  int o=n;
  int rev=0;
  while(n!=0)
  {
    rev*=10;
    rev+=n%10;
    n/=10;
  }
  
  if(o==rev)
      return 1;
  else
      return 0;
}

int main()
{
  int n;
  scanf("%d",&n);
  if(pal(n))
      printf("Yes");
  
  else
     printf("No");
}