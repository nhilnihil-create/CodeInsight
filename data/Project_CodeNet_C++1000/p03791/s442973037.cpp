#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
#define rep(i,n) for(ll i = 0; i < (int)n; i++)

int main(){
  ll n, ans = 1;
  cin >> n;
  ll x[n], g[n] = {};
  rep(i,n) {
    cin >> x[i];
    if(i > 0) g[i] = max(g[i-1],i-(1+x[i-1])/2);
  }
  rep(i,n) (ans *= i + 1 - g[i]) %= mod; 
  cout << ans << endl;
  return 0;
}