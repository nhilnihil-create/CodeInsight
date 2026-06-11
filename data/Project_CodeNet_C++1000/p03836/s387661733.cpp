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

  int64_t sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  const int64_t dx = tx - sx;
  const int64_t dy = ty - sy;
  string result = "";
  result += string(dx, 'R') + string(dy, 'U');
  result += string(dx, 'L') + string(dy, 'D');
  result += string("D") + string(dx + 1, 'R') + string(dy + 1, 'U') + string("L");
  result += string("U") + string(dx + 1, 'L') + string(dy + 1, 'D') + string("R");
  cout << result << endl;

  return 0;
}
