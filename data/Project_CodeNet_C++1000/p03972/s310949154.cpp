#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  int w, h;
  cin >> w >> h;
  vector<ll> p(w), q(h);
  for (ll& x : p) cin >> x;
  for (ll& x : q) cin >> x;

  ll ans = 0;
  rep(i, 0, w) ans += p[i];
  rep(i, 0, h) ans += q[i];

  sort(p.begin(), p.end());
  sort(q.begin(), q.end());

  // すべての(i, j)にたいして、min(p[i], q[j])を足す。
  rep(i, 0, w) {
    ll num = lower_bound(q.begin(), q.end(), p[i]) - q.begin();
    ans += (h - num) * p[i];
  }
  rep(i, 0, h) {
    ll num = upper_bound(p.begin(), p.end(), q[i]) - p.begin();
    ans += (w - num) * q[i];
  }

  //
  cout << ans << endl;
  return 0;
}