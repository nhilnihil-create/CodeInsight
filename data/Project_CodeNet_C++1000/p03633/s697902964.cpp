#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

ll lcm(ll a, ll b){
  ll g = gcd(a,b);
  return a/g*b;
}

int main(){
  int n; cin >>n;
  ll ans = 1LL;
  rep(i,n){
    ll t; cin >>t;
    ans = lcm(ans,t);
  }
  cout << ans << endl;
  return 0;
}