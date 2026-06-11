#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h_total, w_total, h, w;
  cin >> h_total >> w_total >> h >> w;
  if (h_total % h == 0 && w_total % w == 0) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  for (int r = 0; r < h_total; r++) {
    for (int c = 0; c < w_total; c++) {
      int y = r % h;
      int x = c % w;
      if (y == 0 && x == 0) {
        cout << static_cast<int>(1e9) - 1 << " ";
      } else if (y == h - 1 && x == w - 1) {
        cout << static_cast<int>(-1e9) << " ";
      } else {
        cout << 0 << " ";
      }
    }
    cout << endl;
  }
}