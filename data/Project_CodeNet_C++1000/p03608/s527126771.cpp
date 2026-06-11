#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, m, r;
  cin >> n >> m >> r;
  vl v(r);
  rep(i, r) {
    cin >> v[i];
    v[i]--;
  }
  vector<vl> g(n, vl(n, 1e18));
  rep(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g[a][b] = c;
    g[b][a] = c;
  }
  rep(k, n) rep(i, n) rep(j, n) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  ll ans = 1e18;
  sort(all(v));
  do {
    ll now = 0;
    rep(i, r - 1) now += g[v[i]][v[i + 1]];
    ans = min(ans, now);
  } while(next_permutation(all(v)));
  cout << ans << endl;
}