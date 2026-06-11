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

  int64_t a, b, x;
  cin >> a >> b >> x;
  if (x == 1) {
    cout << b - (a - 1) << endl;
  } else {
    int64_t bb = static_cast<int64_t>(b / x);
    int64_t aa = max(static_cast<int64_t>((a - 1) / x), 0L);
    int64_t result = bb - aa;
    if (a == 0) {
      ++result;
    }
    cout << result << endl;
  }
  return 0;
}
