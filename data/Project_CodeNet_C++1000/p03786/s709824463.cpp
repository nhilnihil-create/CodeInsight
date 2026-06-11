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

  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int64_t separate = -1;
  int64_t sum_values = 0;
  for (int64_t i = 0; i <= N - 2; ++i) {
    sum_values += A[i];
    if (sum_values * 2 < A[i + 1]) {
      separate = i;
    }
  }
  cout << N - separate - 1 << endl;

  return 0;
}
