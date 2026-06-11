#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
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

int main() {
  ll n, m;
  cin >> n >> m;
  vl a(n), b(n), c(m), d(m);
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, m) cin >> c[i] >> d[i];
  rep(i, n) {
    ll ans, mn = 1e18;
    rep(j, m) {
      ll now = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if(mn <= now) continue;
      mn = now;
      ans = j + 1;
    }
    cout << ans << '\n';
  }
}