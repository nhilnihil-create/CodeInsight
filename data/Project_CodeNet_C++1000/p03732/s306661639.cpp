#include <bits/stdc++.h>

#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

main() {
  int64_t n, W;
  cin >> n >> W;

  int64_t offset;
  vector<pair<int64_t, int64_t>> wv(n);
  for (auto i : irange(0L, n)) {
    cin >> wv[i].first >> wv[i].second;
    if (i == 0) {
      offset = wv[i].first;
    }
    wv[i].first -= offset;
  }

  vector<vector<int64_t>> dp(n + 1, vector<int64_t>(3 * n + 1));
  for (auto i : irange(0L, n)) {
    auto w = wv[i].first;
    auto v = wv[i].second;
    for (auto j : irange(1L, n + 1) | reversed) {
      for (auto k : irange(w, 3 * n + 1) | reversed) {
        dp[j][k] = max(dp[j][k], dp[j - 1][k - w] + v);
      }
    }
  }

  int64_t ans = -1;
  for (auto i : irange(0L, n + 1)) {
    if (W >= offset * i) {
      ans = max(ans, dp[i][min(W - offset * i, 3 * n)]);
    }
  }
  cout << ans << endl;
}