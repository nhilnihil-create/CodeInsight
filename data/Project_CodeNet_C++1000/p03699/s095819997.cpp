/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int32_t neighbours[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t N;
  cin >> N;
  vector<int32_t> S(N);
  int32_t total_sum = 0;
  for (int32_t i = 0; i < N; ++i) {
    cin >> S[i];
    total_sum += S[i];
  }
  int32_t result = 0;
  if (total_sum % 10 > 0) {
    result = total_sum;
  } else {
    sort(S.begin(), S.end());
    for (int32_t i = 0; i < N; ++i) {
      if (S[i] % 10 > 0) {
        result = total_sum - S[i];
        break;
      }
    }
  }
  cout << result << endl;

  return 0;
}
