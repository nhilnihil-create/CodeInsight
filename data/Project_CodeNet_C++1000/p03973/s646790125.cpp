#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll& x : a) cin >> x;

  ll ans = 0;
  ll mx = 1;
  rep(i, 0, n) {
    if (a[i] < mx) continue;
    if (a[i] == mx) {
      ++mx;
      continue;
    }
    ll yoyu = a[i] - mx;
    ans += (yoyu + mx - 1) / mx;
    if (mx == 1) ++mx;
  }

  cout << ans << endl;

  return 0;
}