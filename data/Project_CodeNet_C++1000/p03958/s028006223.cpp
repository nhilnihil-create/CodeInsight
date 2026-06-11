/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t K, T;
  cin >> K >> T;
  int64_t max_volume = INT64_MIN;
  for (int64_t i = 0; i < T; ++i) {
    int64_t a;
    cin >> a;
    if (a > max_volume) {
      max_volume = a;
    }
  }
  cout << max(0L, max_volume - 1 - (K - max_volume)) << endl;
  return 0;
}
