#include <iostream>

int main() {
  uint32_t A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;
  std::cin >> A >> B >> C >> D >> E >> F;
  A *= 100;
  B *= 100;

  double max_concentration = 0.0;
  uint32_t ans_water = 0, ans_salt = 0;
  for (size_t a = 0; a <= F / A; a++) {
    for (size_t b = 0; b <= F / B; b++) {
      uint32_t water = a * A + b * B;
      if (water == 0 || water > F) break;

      for (size_t c = 0; c <= (F - water) / C; c++) {
        for (size_t d = 0; d <= (F - water) / D; d++) {
          uint32_t salt = c * C + d * D;
          if (salt > E * water / 100 || water + salt > F) break;

          double concentration = static_cast<double>(salt) / (water + salt);
          if (concentration > max_concentration || ans_water == 0) {
            max_concentration = concentration;
            ans_water = water;
            ans_salt = salt;
          }
        }
      }
    }
  }

  std::cout << ans_water + ans_salt << " " << ans_salt << std::endl;

  return 0;
}