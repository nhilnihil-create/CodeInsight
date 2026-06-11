#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll Ep(int x, int y){
  if(y == 0) return 1;
  if(y == 1) return x;
  ll r = Ep(x,y/2);
  if(y%2 == 1) return r *r *x;
  else return r *r;
}
ll comb(ll m, ll n){
  if(m < n) return 0;
  ll x = 1;
  for(int i=0; i<n; ++i){
    x *= m-i;
    x /= i+1;
  }
  return x;
}

int main(){
  int n, p;
  cin >> n >> p;
  int odd = 0, even = 0;
  for(int i=0; i<n; ++i){
    int x;
    cin >> x;
    if(x%2) ++odd;
    else ++even;
  }
  ll ans = 0;
  for(int i=p; i<=odd; i += 2){
    ans += comb(odd, i);
  }
  ans *= Ep(2,even);
  cout << ans << endl;
}