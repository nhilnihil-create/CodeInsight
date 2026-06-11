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

  int64_t N, C, K;
  cin >> N >> C >> K;
  vector<int64_t> T(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> T[i];
  }
  sort(T.begin(), T.end());
  int64_t result = 1;
  int64_t bus_start = T[0] + K;
  int64_t passengers = 1;
  for (int64_t i = 1; i < N; ++i) {
    if (T[i] <= bus_start && passengers + 1 <= C) {
      ++passengers;
    } else {
      bus_start = T[i] + K;
      ++result;
      passengers = 1;
    }
  }
  cout << result << endl;
  return 0;
}
