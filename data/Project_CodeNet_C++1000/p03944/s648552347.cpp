/**
 *   author  : The San Cao (caothesan@gmail.com)
 *   created : 2020.06.05 07:59:05 +07
 */

#include <bits/stdc++.h>

using namespace std;


int main() {
  int W, H, N; cin >> W >> H >> N;
  int x, y, u, v;
  x = y = 0; u = W; v = H;

  for (int i = 0; i < N; ++i) {
    int _x, _y, t; cin >> _x >> _y >> t;
    if (t <= 2) (t - 2) ? x = max(x, _x) : u = min(u, _x);
    else (t - 4) ? y = max(y, _y) : v = min(_y, v);
  }
  cout << (v < y || u < x ? 0 : (u - x) * (v - y)) << "\n";
  return 0;
}

