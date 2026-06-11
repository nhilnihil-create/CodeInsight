// 2020-08-24 21:07:14
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, ll>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  sort(RALL(v));
  int mc = 0;
  ll mv = 0;
  ll last = 1e18;
  auto update = [&](int c, ll w) {
    if(mv * c < w * mc) {
      mc = c;
      mv = w;
      return true;
    }
    return false;
  };
  {
    ll cur = 0;
    rep(i, a) cur += v[i];
    mc = a;
    mv = cur;
    last = v[a-1];
    REP(i, a, b) {
      cur += v[i];
      if(update(i+1, cur)) last = v[i];
    }
    ld ans = ld(mv) / ld(mc);
    cout << fixed << setprecision(6) << ans << '\n';
  }
  if(v[0] == last) {
    ll cnt = 0;
    rep(i, n) cnt += (v[i] == last);
    ll ans = 0, now = 1;
    REPC(i, 1, min(cnt, ll(b))) {
      now = now * (cnt-i+1) / i;
      if(a <= i) ans += now;
    }
    cout << ans << '\n';
  } else {
    ll rem = a, cnt = 0;
    rep(i, n) {
      if(v[i] > last) rem--;
      else if(v[i] == last) cnt++;
      else break;
    }
    ll ans = 1;
    REPC(i, 1, rem) ans = ans * (cnt-i+1) / i;
    cout << ans << '\n';
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}