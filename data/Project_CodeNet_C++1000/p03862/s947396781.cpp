#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
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
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (ll& b : a) cin >> b;

  ll ans = 0;
  rep(i, 0, n - 1) {
    if (a[i] + a[i + 1] > x) {
      ll d = a[i] + a[i + 1] - x;
      ans += d;
      a[i + 1] = max((ll)0, a[i + 1] - d);
    }
  }
  cout << ans << endl;

#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}