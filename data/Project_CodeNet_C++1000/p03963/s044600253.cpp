#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
   ll n,k,x,y,i,j,q;
   vector<ll>v,u;
   ll sum=0;
   cin>>n>>k;
  ll ans=k;
  for(i=0;i<n-1;i++)
  {
      ans*=(k-1);
  }
  cout<<ans<<endl;
    return 0;
}
