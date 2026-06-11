#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
const int MOD = 1e9 + 7; 
int main() {
  ll n,m;
  cin >> n >> m;
  if (n < m) swap(n,m);
  ll ans;
  if (n == m) {
    ans = 2;
    rep(j,2) rep(i,n) {ans *= (i+1); ans %= MOD;}
  } else if (n == m+1) {
    ans = 1;
    rep(i,n) {ans *= (i+1); ans %= MOD;}
    rep(i,m) {ans *= (i+1); ans %= MOD;}
  }
  else ans = 0;
  cout << ans << endl;
  return 0;
}