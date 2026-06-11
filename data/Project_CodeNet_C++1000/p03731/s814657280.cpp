#include<bits/stdc++.h>
using namespace std;

#define rep(i,m) for(int i = 0; i < m; i++)
using ll = long long;

int main(){
  ll n,T;
  cin >> n >> T;
  vector<ll> t(n);
  rep(i,n) cin >> t.at(i);
  ll ans = 0;
  rep(i,n-1){
    ll dif = t.at(i+1)-t.at(i);
    if(dif>=T){
      ans+=T;
    }else ans+=dif;
  }
  ans+=T;
  cout<<ans<<endl;
  return 0;
}
