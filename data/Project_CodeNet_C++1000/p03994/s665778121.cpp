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

  string S;
  int64_t K;
  cin >> S >> K;
  constexpr int64_t kNum = 'z' - 'a' + 1;
  const int64_t L = static_cast<int64_t>(S.length());

  string result = S;

  for (int64_t i = 0; i < L; ++i) {
    const char ch = S.c_str()[i];
    if (ch == 'a') {
      continue;
    }
    const int64_t d = kNum - static_cast<int64_t>(ch - 'a');
    if (K < d) {
      continue;
    }
    K -= d;
    result[i] = 'a';
  }

  K = K % kNum;

  result[L - 1] += K;

  cout << result << endl;
  return 0;
}
