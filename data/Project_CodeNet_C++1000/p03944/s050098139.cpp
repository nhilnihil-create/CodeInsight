#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  vector<int> x(n), y(n), a(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> a[i];

  int y_max(h), y_min(0);
  int x_max(w), x_min(0);
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      x_min = max(x_min, x[i]);
    } else if (a[i] == 2) {
      x_max = min(x_max, x[i]);
    } else if (a[i] == 3) {
      y_min = max(y_min, y[i]);
    } else if (a[i] == 4) {
      y_max = min(y_max, y[i]);
    }
  }
  int ans = (x_max - x_min) * (y_max - y_min);
  if (x_max - x_min < 0 || y_max - y_min < 0) ans = 0;

  cout << ans << endl;
}
