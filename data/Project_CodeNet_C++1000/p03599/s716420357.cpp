#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int water = 0, sugar = 0;
  for (int k = 0; 100*k*a <= f; ++k) 
    for (int l = 0; 100*l*b <= f; ++l) {
      int w = 100 * (k*a + l*b);
      for (int r = 0; r*c + w <= f; ++r) 
        for (int u = 0; u*c + w <= f; ++u) {
          int s = r*c + u*d;
          if (w + s <= f) {
            if (s <= w/100 * e) {
              if (s * (water + sugar) >= sugar * (w + s)) {
                water = w;
                sugar = s;
              }
            }
          }
        }
    }


  cout << water+sugar << " " << sugar << endl;

  return 0;
}

