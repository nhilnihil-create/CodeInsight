#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;

  int k = 4000;

  static int a[510][510];
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      a[i][j] = k;
    }
  }
  for (int i = h; i <= H; i += h) {
    for (int j = w; j <= W; j += w) {
      a[i][j] = -(h * w - 1) * k - 1;
    }
  }

  int sum = 0;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      sum += a[i][j];
    }
  }

  if (sum <= 0) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (j != 1) cout << " ";
      cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}
