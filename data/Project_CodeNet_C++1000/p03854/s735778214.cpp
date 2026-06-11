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
  cin >> S;
  vector<string> texts = {"dream", "dreamer", "erase", "eraser"};
  auto Dfs = [&](auto &&Func, const int64_t i) -> bool {
    if (i >= static_cast<int64_t>(S.length())) {
      return true;
    }
    bool result = false;
    for (auto text : texts) {
      const int64_t n = static_cast<int64_t>(text.length());
      if (S.substr(i, n) == text) {
        result = Func(Func, i + n);
        if (result) {
          break;
        }
      }
    }
    return result;
  };
  const bool result = Dfs(Dfs, 0);
  if (result) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
