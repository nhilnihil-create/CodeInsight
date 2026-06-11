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

  int32_t a, b;
  cin >> a >> b;
  if (a <= 0 && b >= 0) {
    cout << "Zero" << endl;
  } else if (a > 0) {
    cout << "Positive" << endl;
  } else {
    if ((b - a + 1) % 2 == 0) {
      cout << "Positive" << endl;
    } else {
      cout << "Negative" << endl;
    }
  }

  return 0;
}
