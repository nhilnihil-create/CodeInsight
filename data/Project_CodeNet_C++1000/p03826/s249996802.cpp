#include <bits/stdc++.h>

using namespace std;

int main()
{
   int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  long int ans1=a*b;
  long int ans2=c*d;
  
  if(ans1>=ans2)
       printf("%ld",ans1);
  
  else
     printf("%ld",ans2);
}