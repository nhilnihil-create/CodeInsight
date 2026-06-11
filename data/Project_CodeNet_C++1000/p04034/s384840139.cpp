#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n,m;
  cin >> n >> m;
  vector<ll> b(n,1);
  vector<bool> r(n,false);
  r[0] = true;
  rep(i,m){
    ll x,y;
    cin >> x >> y;
    x--;
    y--;
    b[x]--;
    b[y]++;
    if(r[x]){
      r[y] = true;
    }
    if(b[x] == 0){
      r[x] = false;
    }
  }
  
  ll cnt=0;
  
  rep(i,n){
    if(b[i]>0 && r[i]){
      cnt++;
    }
  }
  
  cout << cnt << endl;
  
  return(0);
}