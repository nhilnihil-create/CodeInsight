#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  if (H % h == 0 && W % w == 0) {
    cout << "No" << endl;
    return 0;
  }
  int minus = (H / h) * (W / w);
  int rem = H * W - h * w * minus;
  int pv = minus / rem + 1;
  int mv = -((h * w - 1) * pv + 1);
  cout << "Yes" << endl;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i % h == h - 1 && j % w == w - 1) {
        cout << mv;
      } else {
        cout << pv;
      }
      cout << " ";
    }
    cout << endl;
  }
  return 0;
}
