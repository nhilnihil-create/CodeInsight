#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  rep(i, 0, n) cin >> v[i].first >> v[i].second;
  ll ans = 0;
  repr(i, 0, n) {
    ll t = v[i].first + ans;
    if (t % v[i].second)
      ans += v[i].second - (t % v[i].second);
  }

  cout << ans << endl;
}
