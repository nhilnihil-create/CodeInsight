#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int ans_w = 100 * a, ans_s = 0;
  // wx: 操作1を行う回数, wy: 操作2を行う回数
  for (int wx = 0; 100 * a * wx <= f; wx++) {
    for (int wy = 0; 100 * b * wy <= f; wy++) {
      int water = 100 * a * wx + 100 * b * wy;
      if (water > f) {
        continue;
      }
      // sx: 操作3を行う回数, sy: 操作4を行う回数
      int su_lim = f - water;
      for (int sx = 0; sx * c <= su_lim; sx++) {
        for (int sy = 0; sy * d <= su_lim; sy++) {
          int sugar = sx * c + sy * d;
          if (water + sugar > f) {
            continue;
          }
          if (sugar * 100 <= e * water) {
            if (ans_s * (sugar + water) <= sugar * (ans_s + ans_w)) {
              ans_s = sugar;
              ans_w = water;
            }
          }
        }
      }
    }
  }
  cout << ans_s + ans_w << " " << ans_s << endl;
  return 0;
}
