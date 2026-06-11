#include<bits/stdc++.h>
using namespace std;
int main () {
  int sx, sy, gx, gy;
  int N;
  cin >> gx >> gy >> N;
  sx = sy = 0;
  for (int i = 0; i < N; i ++) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) sx = max(sx, x);
    if (a == 2) gx = min(gx, x);
    if (a == 3) sy = max(sy, y);
    if (a == 4) gy = min(gy, y);
  }
  if (sx >= gx || sy >= gy) {
    cout << 0 << endl;
    return 0;
  }
  cout << (gx - sx) * (gy - sy) << endl;
}
