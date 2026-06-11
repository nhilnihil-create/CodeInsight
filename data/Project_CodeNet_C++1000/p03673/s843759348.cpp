#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
const ll INF = 999999999999999;
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a.at(i);
  if( n%2 == 0 ){
    for(ll i=n-1;i>=0;--i){
      if( (i+1)%2 == 0 ){
        cout << a.at(i) << " ";
      }
    }
    for(ll i=0;i<n;++i){
      if( (i+1)%2 == 1 ){
        cout << a.at(i) << " ";
      }
    }
  }else{
    for(ll i=n-1;i>=0;--i){
      if( (i+1)%2 == 1 ){
        cout << a.at(i) << " ";
      }
    }
    for(ll i=0;i<n;++i){
      if( (i+1)%2 == 0 ){
        cout << a.at(i) << " ";
      }
    }
  }
  cout << endl;
  return 0;
}