/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

bool IsOkay(const string &s) {
  const int32_t length = static_cast<int32_t>(s.length());
  if (length % 2 != 0) {
    return false;
  }
  const int32_t half = length / 2;
  return (s.substr(0, half) == s.substr(half, half));
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  const int32_t length = static_cast<int32_t>(S.length());
  for (int32_t i = length - 2; i >= 2; i -= 2) {
    if (IsOkay(S.substr(0, i))) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
