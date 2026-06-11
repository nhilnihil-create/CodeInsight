#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  int sx, sy, tx, ty, dx, dy;
  cin >> sx >> sy >> tx >> ty;
  dx = tx - sx;
  dy = ty - sy;
  cout << string(dy, 'U') << string(dx, 'R');
  cout << string(dy, 'D') << string(dx, 'L');
  cout << "L" << string(dy + 1, 'U') << string(dx + 1, 'R') << "D";
  cout << "R" << string(dy + 1, 'D') << string(dx + 1, 'L') << "U";
  cout << endl;
  getchar();
}