#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<ll> a(n), b(n);
  ll ans = 0;
  rep(i,n) cin >> a[i] >> b[i];
  for (int i = n-1; i>=0; i--) {
    a[i] += ans;
    ll x = a[i] % b[i];
    if (x) ans += b[i] - x;
  }
  cout << ans << endl;
  return 0;
}