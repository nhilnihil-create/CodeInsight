#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

ll inf = 1001001001;

int main() {
  ll n;
  cin >> n;
  vector<vl> g(n, vl(n));
  vector<vb> e(n, vb(n, true));
  bool ok = true;
  rep(i, n) rep(j, n) cin >> g[i][j];
  rep(k, n) rep(i, n) rep(j, n) {
    if(k == i || k == j) continue;
    ll now = g[i][k] + g[k][j];
    if(g[i][j] > now)
      ok = false;
    else if(g[i][j] == now) {
      e[i][j] = false;
      e[j][i] = false;
    }
  }
  ll ans = 0;
  if(ok) {
    rep(i, n - 1) rep2(j, i + 1, n) if(e[i][j]) ans += g[i][j];
    cout << ans << endl;

  } else
    cout << -1 << endl;
}