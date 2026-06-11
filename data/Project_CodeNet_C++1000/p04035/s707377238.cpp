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
  ll n, l;
  cin >> n >> l;
  vector<ll> a(n);
  for (ll& x : a) cin >> x;

  int left = -1;
  rep(i, 0, n - 1) {
    if (a[i] + a[i + 1] >= l) {
      left = i;
      break;
    }
  }
  if (left != -1) {
    cout << "Possible" << '\n';
    rep(i, 0, left) cout << i + 1 << '\n';
    rrep(i, left, n - 1) cout << i + 1 << '\n';
  } else
    cout << "Impossible" << '\n';
  return 0;
}