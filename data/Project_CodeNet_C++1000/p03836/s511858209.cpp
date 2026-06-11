#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  const int dx = tx - sx, dy = ty - sy;

  // Path1
  cout << string(dy, 'U') << string(dx, 'R');

  // Path2
  cout << string(dy, 'D') << string(dx, 'L');

  // Path3
  cout << 'L' << string(dy + 1, 'U') << string(dx + 1, 'R') << 'D';

  // Path4
  cout << 'R' << string(dy + 1, 'D') << string(dx + 1, 'L') << 'U';
  cout << endl;

  return 0;
}
