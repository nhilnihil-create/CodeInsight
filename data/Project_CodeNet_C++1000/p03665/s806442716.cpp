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

  int64_t N, P;
  cin >> N >> P;
  int64_t even = 0;
  int64_t odd = 0;
  for (int64_t i = 0; i < N; ++i) {
    int64_t a;
    cin >> a;
    if (a % 2 == 0) {
      ++even;
    } else {
      ++odd;
    }
  }
  int64_t result = 0;
  if (odd == 0) {
    result = (P == 0) ? (1LL << N) : 0;
  } else {
    result = 1LL << (N - 1);
  }
  cout << result << endl;
  return 0;
}
