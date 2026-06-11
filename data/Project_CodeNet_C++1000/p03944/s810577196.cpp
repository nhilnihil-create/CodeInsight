#include<bits/stdc++.h>
// #include "atcoder/modint"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

int main(){
  ll w,h,n;cin >> w >> h >> n;
  vector<string> field(h);
  rep(i,h) field.at(i).resize(w);
  rep(i,h) rep(j,w) field.at(i).at(j) = 'o';

  rep(i,n){
    ll x,y,a;cin >> x >> y >> a;
    if( a == 1 ){
      rep(j,h){
        for(ll k=0;k<x;++k) field.at(j).at(k) = 'x';
      }
    }else if( a == 2 ){
      rep(j,h){
        for(ll k=x;k<w;++k) field.at(j).at(k) = 'x';
      }
    }else if( a == 3 ){
      for(ll j=1;j<=y;++j){
        rep(k,w) field.at(h-j).at(k) = 'x';
      }
    }else if( a == 4 ){
      for(ll j=h-y-1;j>=0;--j){
        rep(k,w) field.at(j).at(k) = 'x';
      }
    }
  }

  ll ans = 0;
  rep(i,h) rep(j,w) if( field.at(i).at(j) == 'o' ) ans++;

  cout << ans << endl;

  // rep(i,h){
  // 	rep(j,w) cout << field.at(i).at(j) << " ";
  // 	cout << endl;
  // }

  return 0;
}