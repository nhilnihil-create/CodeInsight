/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, K;
  cin >> N >> K;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> D(K);
  for (int64_t i = 0; i < K; ++i) {
    cin >> D[i];
  }
  auto IsOkay = [&](const int64_t n) -> bool {
    int64_t temp = n;
    do {
      const int64_t digit = temp % 10;
      for (const auto &comp : D) {
        if (digit == comp) {
          return false;
        }
      }
      temp /= 10;
    } while (temp > 0);
    return true;
  };

  for (int64_t i = N; i <= N * 20; ++i) {
    if (IsOkay(i)) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
