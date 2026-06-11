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

  int n, m, r;
  cin >> n >> m >> r;
  vector<int> rv(r);
  rep(i, 0, r) {
    cin >> rv[i];
    rv[i]--;
  }

  vector<vector<ll>> d(n, vector<ll>(n, 1e18));
  rep(i, 0, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    d[a][b] = c;
    d[b][a] = c;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);

  sort(rv.begin(), rv.end());
  ll ans = 1e18;
  do {
    ll x = 0, from = rv[0];
    rep(to, 1, r) {
      x += d[from][rv[to]];
      from = rv[to];
    }
    chmin(ans, x);
  } while (next_permutation(rv.begin(), rv.end()));

  cout << ans << endl;
}
