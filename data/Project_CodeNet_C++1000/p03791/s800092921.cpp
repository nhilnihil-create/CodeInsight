#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll mod = 1e9+7;

int main(){
  int n;
  cin >> n;
  ll x[n], g[n] = {};
  for(ll i = 0; i < n; i++) {
    cin >> x[i];
    if(i > 0) {
      g[i] = max(g[i-1],i-(1+x[i-1])/2);
    }
  }
  ll ans = 1;
  for(ll i = 0; i < n; i++) {
    (ans *= i + 1 - g[i] ) %= mod; 
  }
  cout << ans << endl;
  return 0;
}