#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,x,ans=0;
  cin>>n;
  while(n--)
  {
  	cin>>x;
  	ans+=x;
  }
  if(ans&1)
  cout<<"NO\n";
  else
  cout<<"YES\n";
  return 0;
}