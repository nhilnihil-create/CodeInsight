#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;

int main() {
  ll n, c, k;
  cin >> n >> c >> k;
  vector<ll> t(n);
  rep(i, 0, n) cin >> t[i];
  sort(t.begin(), t.end());

  int ans = 1;
  int cnt = 1;
  int start = t[0];
  rep(i, 1, n) {
    if (t[i] <= start + k && cnt + 1 <= c) {
      ++cnt;
    } else {
      ++ans;
      start = t[i];
      cnt = 1;
    }
  }
  cout << ans << endl;
  return 0;
}