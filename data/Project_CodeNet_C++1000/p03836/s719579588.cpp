#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  string ans;
  int h1 = ty - sy, w1 = tx - sx;
  rep(i, abs(h1)) ans += (h1 > 0 ? 'U' : 'D');
  rep(i, abs(w1)) ans += (w1 > 0 ? 'R' : 'L');

  int h2 = sy - ty, w2 = sx - tx;
  rep(i, abs(h2)) ans += (h2 > 0 ? 'U' : 'D');
  rep(i, abs(w2)) ans += (w2 > 0 ? 'R' : 'L');

  int h3 = ty - sy, w3 = tx - sx;
  ans += (w3 > 0 ? 'L' : 'R');
  rep(i, abs(h3) + 1) ans += (h3 > 0 ? 'U' : 'D');
  rep(i, abs(w3) + 1) ans += (w3 > 0 ? 'R' : 'L');
  ans += (h3 > 0 ? 'D' : 'U');

  int h4 = sy - ty, w4 = sx - tx;
  ans += (w4 > 0 ? 'L' : 'R');
  rep(i, abs(h4) + 1) ans += (h4 > 0 ? 'U' : 'D');
  rep(i, abs(w4) + 1) ans += (w4 > 0 ? 'R' : 'L');
  ans += (h4 > 0 ? 'D' : 'U');

  cout << ans << endl;
  return 0;
}
