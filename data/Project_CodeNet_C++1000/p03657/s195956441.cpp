#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a,b;
  cin>>a>>b;
  if(a%3==0)
  {
    cout<<"Possible";
    return 0;
  }
  if(b%3==0)
  {
    cout<<"Possible";
    return 0;
  }
  if((a+b)%3==0)
  {
    cout<<"Possible";
    return 0;
  }
  cout<<"Impossible";
  return 0;
}