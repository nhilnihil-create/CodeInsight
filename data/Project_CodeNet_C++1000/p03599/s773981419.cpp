#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int ans_sugar, ans_total;
  double density = -1.0;
  for (int i = 0; i * a * 100 <= f; i++) {
    for (int j = 0; j * b * 100 <= f; j++) {
      for (int k = 0; k * c <= f; k++) {
        for (int l = 0; l * d <= f; l++) {
          int water = i * a * 100 + j * b * 100;
          int sugar = k * c + l * d;
          int total = sugar + water;
          if (total == 0) continue;
          if (total > f) continue;
          if (sugar * 100 > e * water) continue;
          if (density < 100 * sugar / (double)total) {
            density = 100 * sugar / (double)total;
            ans_sugar = sugar;
            ans_total = total;
          }
        }
      }
    }
  }

  cout << ans_total << " " << ans_sugar << endl;
}