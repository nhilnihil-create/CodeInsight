#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
  long int w,a,b;
  scanf("%ld%ld%ld",&w,&a,&b);
  if((a+w)>=b && b>=a)
      printf("0");
  
  else if(b+w>=a && a>=b)
      printf("0");
  else
  {
  int ans1=abs(b-(a+w));
  int ans2=abs(a-(b+w));
    printf("%d",min(ans1,ans2));
  }
}