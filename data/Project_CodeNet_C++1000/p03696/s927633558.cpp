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
  string S;
  cin >> N >> S;
  const int64_t L = static_cast<int64_t>(S.length());
  int64_t count = 0;
  string result = "";
  for (int64_t i = 0; i < L; ++i) {
    const char ch = S.c_str()[i];
    if (ch == '(') {
      result += "(";
      ++count;
    } else {
      if (count > 0) {
        result += ")";
        --count;
      } else {
        result = "(" + result + ")";
      }
    }
  }
  while (count > 0) {
    result += ")";
    --count;
  }
  cout << result << endl;
  return 0;
}
