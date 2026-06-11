/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, A, B;
  cin >> N >> A >> B;

  if (B < A) {
    cout << 0 << endl;
  } else if (B > A && N == 1) {
    cout << 0 << endl;
  } else {
    const int64_t min_value = A * (N - 1) + B;
    const int64_t max_value = A + B * (N - 1);
    cout << (max_value - min_value + 1) << endl;
  }

  return 0;
}
