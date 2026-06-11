#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  if (H % h == 0 && W % w == 0) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      if (c > 0) cout << " ";
      if (r % h == 0 && c % w == 0) cout << (int) 1e9 - 1;
      else if (r % h == h - 1 && c % w == w - 1) cout << (int) -1e9;
      else cout << 0;
    }
    cout << '\n';
  }
  return 0;
}