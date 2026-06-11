#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  double e, f;
  cin >> a >> b >> c >> d >> e >> f;
  double t = 0;
  int p = 0;
  int q = 0;
  bool x = false;
  for (int i = 0; 100 * i <= f; i += a) {
    for (int j = 0; 100 * i + 100 * j <= f; j += b) {
      for (int k = 0; 100 * i + 100 * j + k <= f; k += c) {
        for (int l = 0; 100 * i + 100 * j + k + l <= f; l += d) {
          double w = 100 * i + 100 * j;
          double s = k + l;
          if (w == 0) {
            continue;
          }
          if (s / w > t && s / w <= e / 100) {
            t = s / w;
            p = w + s;
            q = s;
            x = true;
          }
        }
      }
    }
  }
  if (x) cout << p << " " << q << endl;
  else cout << a * 100 << " " << 0 << endl;
}