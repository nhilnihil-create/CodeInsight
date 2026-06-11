#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  float saturation_diff = 1.0f;
  int saturation_total = 0;
  int saturation_suger = 0;

  float max_ratio = (float)E / (100.f + (float)E);
  float max_water = F / 100;
  float max_suger = F * max_ratio;

  for (int a = 0; a < max_water / A; a++) {
    for (int b = 0; b < max_water / B; b++) {
      for (int c = 0; c < max_suger / C; c++) {
        for (int d = 0; d < max_suger / D; d++) {
          int water = (100 * A) * a + (100 * B) * b;
          int suger = C * c + D * d;
          int total = water + suger;
          if (100 * A > total || total > F || total == 0) continue;

          float ratio = (float)suger / (float)total;
          float diff = max_ratio - ratio;
          if (ratio <= max_ratio && diff < saturation_diff) {
            saturation_diff = diff;
            saturation_total = total;
            saturation_suger = suger;
          }
        }
      }
    }
  }

  cout << saturation_total << ' ' << saturation_suger << endl;
}