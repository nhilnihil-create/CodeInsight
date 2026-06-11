#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n,a,b;
  cin>>n>>a>>b;ll x[n];
 ll ans=0;
  for(int i=0;i<n;i++)
  {
    cin>>x[i];
  }
  for(int i=1;i<n;i++)
  {
    ans=ans+min((x[i]-x[i-1])*a, b);
  }
  cout<<ans;
}