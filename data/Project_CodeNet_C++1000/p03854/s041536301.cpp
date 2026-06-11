/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

const vector<string> templates = {"dream", "dreamer", "erase", "eraser"};
string S;
int64_t N;

bool Dfs(const int64_t pos) {
  if (pos == N) {
    return true;
  } else if (pos > N) {
    return false;
  }
  for (const auto compare : templates) {
    const int64_t temp_length = static_cast<int64_t>(compare.length());
    if (S.substr(pos, temp_length) == compare) {
      const bool is_okay = Dfs(pos + temp_length);
      if (is_okay) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> S;
  N = static_cast<int64_t>(S.length());
  const bool is_okay = Dfs(0);
  if (is_okay) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
