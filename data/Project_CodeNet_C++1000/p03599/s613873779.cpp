// 2020-09-23 23:07:13
// clang-format off
#include <bits/stdc++.h>
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
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

// clang-format on
void answer() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  set<int> ss, ws;
  {
    repc(i, 1500) repc(j, 1500) {
      int k = c * i + d * j;
      if (k <= f) ss.insert(k);
    }
    repc(i, 30) repc(j, 15) {
      int k = 100 * a * i + 100 * b * j;
      if (0 < k && k <= f) ws.insert(k);
    }
  }
  int anss = 0, answ = 0, mx = -1;
  for (auto s : ss)
    for (auto w : ws) {
      bool ok = true;
      ok &= (s + w <= f);
      ok &= (s * 100 <= e * w);
      if (ok && chmax(mx, 10000 * s / (s + w))) {
        anss = s;
        answ = w;
      }
    }
  cout << anss + answ << ' ' << anss << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}