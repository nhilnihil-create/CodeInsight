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

  string s;
  cin >> s;
  set<char> characters;
  for (char ch : s) {
    characters.insert(ch);
  }
  if (characters.size() == 1) {
    cout << 0 << endl;
    return 0;
  }
  int64_t result = INT64_MAX;
  for (const char target : characters) {
    string temp = s;
    int64_t count = 0;
    while (true) {
      bool dirty = false;
      ++count;
      string current;
      swap(current, temp);
      const int64_t L = static_cast<int64_t>(current.length());
      for (int64_t i = 0; i <= L - 2; ++i) {
        if (current[i] == target || current[i + 1] == target) {
          temp.push_back(target);
        } else {
          temp.push_back(current[i]);
          dirty = true;
        }
      }
      if (!dirty) {
        break;
      }
    }
    result = min(result, count);
  }
  cout << result << endl;
  return 0;
}
