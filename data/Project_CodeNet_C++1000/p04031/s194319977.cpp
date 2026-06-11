#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N; cin>>N;
  vector<ll> a(N);
  ll ans=1e7;
  rep(i,N)
  {
    cin>>a.at(i);
  }
  rep(i,101)
  {
    ll l=i,min1=0,min2=0;
    rep(j,N)
    {
      l=abs(l);
      ll a_j=a.at(j);
      min1+=(a_j-l)*(a_j-l);
      l=-l;
      min2+=(a_j-l)*(a_j-l);
    }
    ans=min(ans,min(min1,min2));
  }  
  cout<<ans<<endl;
  return 0;
}
