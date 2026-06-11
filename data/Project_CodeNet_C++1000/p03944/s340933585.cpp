#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W, N, x, y, a, x1, x2, y1, y2;
  for (cin >> W >> H >> N, x1 = 0, y1 = 0, x2 = W, y2 = H;  N; N--) {
    cin >> x >> y >> a;
    if (a == 1) {
      x1 = max(x,x1);
    } else if (a == 2) {
      x2 = min(x,x2);
    } else if (a == 3) {
      y1 = max(y,y1);
    } else {
      y2 = min(y,y2);
    }
  }
  if (x2 <= x1 || y2 <= y1) {
    cout << 0;
  } else {
    cout << (x2-x1)*(y2-y1);
  }
}