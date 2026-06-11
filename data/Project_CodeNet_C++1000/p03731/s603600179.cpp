#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,t;
  cin>>n>>t;
  vector<int> v(n);
  for(int &i:v) cin>>i;
  int ans=0,l=0;
  for(int i:v)
  {
    if(l>i)
    {
      ans -= (l-i);
      ans += t;
      l = i+t;
    }
    else
    {
      ans+=t;
      l=i+t;
    }
  }
  cout<<ans;
  
  return 0;
}