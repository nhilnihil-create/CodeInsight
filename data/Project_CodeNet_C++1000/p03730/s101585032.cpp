/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t A, B, C;
  cin >> A >> B >> C;

  bool is_okay = false;
  for (int32_t i = 1; i <= B; ++i) {
    if ((i * A) % B == C) {
      is_okay = true;
    }
  }
  if (is_okay) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
