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

  int64_t H, W;
  cin >> H >> W;
  vector<string> result(H * 2, string(" ", W));
  for (int64_t r = 0; r < H; ++r) {
    string s;
    cin >> s;
    for (int64_t c = 0; c < W; ++c) {
      result[r * 2][c] = s[c];
      result[r * 2 + 1][c] = s[c];
    }
  }
  for (auto a : result) {
    cout << a << endl;
  }
  return 0;
}
