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

  int64_t N, x;
  cin >> N >> x;
  // const int64_t L = static_cast<int64_t>(T.length());
  int64_t result = 0;
  vector<int64_t> A(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i];
    if (A[i] > x) {
      result += A[i] - x;
      A[i] = x;
    }
    if (i >= 1 && A[i - 1] + A[i] > x) {
      const int64_t d = A[i - 1] + A[i] - x;
      A[i] -= d;
      result += d;
    }
  }
  cout << result << endl;
  return 0;
}
