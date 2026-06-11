#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

//引数の整数の約数が入った配列を返す関数
vector<ll> func( ll n ){
  vector<ll> a;
  for(ll i=1;i*i<=n;++i){
    if( n%i == 0 ) a.push_back(i);
  }
  return a;
}

ll keta( ll n ){
  if( n == 0 ) return 0;
  return 1 + keta(n/10);
}


int main() {
  ll n;cin >> n;
  vector<ll> a = func(n);
  
  // rep(i,a.size()) cout << a.at(i) << " ";
  // cout << endl;

  ll ans = 9999999999;
  for(ll i=0;i<a.size();++i){
    ll an = a.at(i);
    ll bn = n/an;
    ans = min(ans,max(keta(an),keta(bn)));
  }
  cout << ans << endl;
  return 0;
}