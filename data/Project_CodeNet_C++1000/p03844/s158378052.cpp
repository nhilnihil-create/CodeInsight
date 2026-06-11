#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b;
  char ch;
  scanf("%lld %c %lld",&a,&ch,&b);
  if(ch=='-')printf("%lld\n",a-b);
  else printf("%lld\n",a+b);
}