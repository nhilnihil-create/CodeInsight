#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int a;
  cin>>a;
  int max=0,cnt=0;
  for(int i=1;i<=a;i++)
  {
    int ct=0;
    int x=i;
    while(x%2==0)
    {
      ct++;
      x/=2;
    }
    if(ct>=cnt)
    {
      max=i;
      cnt=ct;
    }
  }
  cout<<max;
  return 0;
}