#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;



int main() 
{
  ll N,K; cin>>N>>K;
  vector<pair<ll,ll>> ab(N);
  rep(i,N)
  {
    ll a,b; cin>>a>>b;
    ab.at(i)=pair<ll,ll> (a,b);
  }
  sort(ab.begin(),ab.end());
  ll sum=0;
  for(ll i=0;;i++)
  {
    sum+=ab.at(i).second;
    if(sum>=K)
    {
      cout<<ab.at(i).first<<endl;
      break;
    }  
  }  
  return 0;
}