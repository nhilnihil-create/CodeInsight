#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  int point[w + 1][h + 1];
  for (int i = 0; i < w + 1; i++) {
    for (int j = 0; j < h + 1; j++) {
      point[i][j] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      for (int i = 0; i < x; i++) {
        for (int j = 0; j < h + 1; j++) {
          point[i][j] = 0;
        }
      }
    } else if (a == 2) {
      for (int i = x; i < w + 1; i++) {
        for (int j = 0; j < h + 1; j++) {
          point[i][j] = 0;
        }
      }
    } else if (a == 3) {
      for (int i = 0; i < w + 1; i++) {
        for (int j = 0; j < y; j++) {
          point[i][j] = 0;
        }
      }
    } else {
      for (int i = 0; i < w + 1; i++) {
        for (int j = y; j < h + 1; j++) {
          point[i][j] = 0;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      ans += point[i][j];
    }
  }

  cout << ans << endl;
  return 0;
}
