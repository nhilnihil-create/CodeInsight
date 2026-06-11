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

  vector<string> templates = {"dream", "dreamer", "erase", "eraser"};
  for (auto &compare : templates) {
    reverse(compare.begin(), compare.end());
  }
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  const int64_t N = static_cast<int64_t>(S.length());
  int64_t pos = 0;
  bool is_okay = true;
  while (pos < N) {
    bool matched = false;
    for (const auto &compare : templates) {
      const int64_t cm_len = static_cast<int64_t>(compare.length());
      if (S.substr(pos, cm_len) == compare) {
        pos += cm_len;
        matched = true;
        break;
      }
    }
    if (!matched) {
      is_okay = false;
      break;
    }
  }
  if (is_okay) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
