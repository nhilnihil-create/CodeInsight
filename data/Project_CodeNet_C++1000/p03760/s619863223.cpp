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

  string O, E;
  cin >> O >> E;
  const int64_t L = static_cast<int64_t>(O.length());
  for (int64_t i = 0; i < L; ++i) {
    cout << O[i];
    if (i < static_cast<int64_t>(E.length())) {
      cout << E[i];
    }
  }
  cout << endl;
  return 0;
}
