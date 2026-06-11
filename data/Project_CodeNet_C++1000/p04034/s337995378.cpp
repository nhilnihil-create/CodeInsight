#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll N,M; cin>>N>>M;
  vector<bool> kanou(N,false);
  kanou.at(0)=true;
  vector<ll> kosu(N,1);
  rep(i,M)
  {
    ll x,y; cin>>x>>y;
    x--; y--;
    if(kanou.at(x)) {kanou.at(y)=true;}
    kosu.at(x)--;
    kosu.at(y)++;
    if(kosu.at(x)==0) {kanou.at(x)=false;}
  }
  ll ans=0;
  rep(i,N)
  {
    if(kanou.at(i)) {ans++;}
  }
  cout<<ans<<endl;
  return 0;
}
