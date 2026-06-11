#include <bits/stdc++.h>
using namespace std;

main() {
  int H, W, d; cin >> H >> W >> d;
  string RYGB = "RYGB";
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int color = 0;
      color += (i + j) / d % 2;
      color += (i - j + W) / d % 2 * 2;
      cout << RYGB[color];
    }
    cout << endl;
  }
}
