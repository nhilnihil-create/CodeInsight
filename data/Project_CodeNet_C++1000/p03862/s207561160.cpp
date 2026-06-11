#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  ll ans = 0;
  if (a[0] > x) {
    ans += a[0] - x;
    a[0] = x;
  }
  rep(i, 0, n - 1) {
    if (a[i] + a[i + 1] <= x) continue;
    ans += a[i + 1] + a[i] - x;
    a[i + 1] -= a[i + 1] + a[i] - x;
  }

  cout << ans << endl;

  return 0;
}
