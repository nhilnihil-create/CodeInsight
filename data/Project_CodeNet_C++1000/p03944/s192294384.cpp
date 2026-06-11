#include <iostream>

using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  int ow = 0, oh = 0;
  int x[110] = {0};
  int y[110] = {0};
  int a[110] = {0};
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    cin >> y[i];
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    switch (a[i]) {
    case 1:
      if (ow < x[i]) {
        ow = x[i];
      }
      break;
    case 2:
      if (x[i] < w) {
        w = x[i];
      }
      break;
    case 3:
      if (oh < y[i]) {
        oh = y[i];
      }
      break;
    case 4:
      if (y[i] < h) {
        h = y[i];
      }
      break;
    }
  }
  int ans = 0;
  if (w > ow && h > oh) {
    ans = (w - ow) * (h - oh);
  }
  cout << ans << endl;
  return 0;
}
