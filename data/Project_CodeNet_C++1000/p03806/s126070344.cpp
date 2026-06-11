#include <bits/stdc++.h>

#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

main() {
  // (sum a_i) : (sum b_i) == m_a : m_b
  // sum (a_i * m_b - b_i * m_a) = 0
  int64_t n, m_a, m_b;
  cin >> n >> m_a >> m_b;

  vector<pair<int64_t, int64_t>> items(n);
  for (auto&& t : items) {
    int64_t a, b, c;
    cin >> a >> b >> c;

    t.first = a * m_b - b * m_a;
    t.second = c;
  }

  constexpr auto kOffset = 10000L;
  vector<vector<int64_t>> dp(
      n + 1, vector<int64_t>(20000, numeric_limits<int32_t>::max()));
  for (auto i : irange(0L, n)) {
    for (auto j : irange(0L, 20000L)) {
      if (j - items[i].first >= 0) {
        dp[i + 1][j] =
            min(dp[i][j], dp[i][j - items[i].first] + items[i].second);
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
    dp[i + 1][items[i].first + kOffset] =
        min(dp[i + 1][items[i].first + kOffset], items[i].second);
  }

  if (dp.back()[kOffset] >= numeric_limits<int32_t>::max() / 2) {
    cout << -1 << endl;
  } else {
    cout << dp.back()[kOffset] << endl;
  }
}