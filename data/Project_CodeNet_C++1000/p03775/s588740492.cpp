#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//~ using P = pair<int, int>;

int func(ll a, ll b){
  int diga, digb;
  diga = digb = 0;
  while(a!=0){
    a /= 10;
    diga++;
  }
  while(b!=0){
    b /= 10;
    digb++;
  }
  return max(diga, digb);
}

int main(){
  ll n;
  int m=99;
  
  cin >> n;
  for (ll i=1; i*i<=n; i++) {
    ll j=n/i;
    if(n==i*j) {
      m = min(m, func(i, j));
    }
  }
  
  cout << m << endl;
  return 0;
}
