#include <iostream>

int main()
{
  int A, B, C, D, E, F;
  std::cin >> A >> B >> C >> D >> E >> F;
  A *= 100;
  B *= 100;

  int max_A = F / A;
  int max_B = F / B;
  int max_C = F / C;
  int max_D = F / D;

  //std::cout << "max_A: " << max_A
  //          << "max_B: " << max_B
  //          << "max_C: " << max_C
  //          << "max_D: " << max_D
  //          << std::endl;

  float density = 0.0;
  float max_density = -1;
  int max_water = 0;
  int max_suger = 0;
  for(int a=0; a<=max_A; a++) {
    for(int b=0; b<=max_B; b++) {
      int water = a*A + b*B;
      if(water == 0 || F < water) {
        continue;
      }

      for(int c=0; c<max_C; c++) {
        for(int d=0; d<max_D; d++) {
          int suger = c*C + d*D;
          // not melted
          if(E * (water/100) < suger) continue;
          // too heavy
          if(F < water + suger) continue;

          density = 100 * suger /(float)(water + suger);
          // std::cout <<  "w: " << water
          //           << " s: " << suger
          //           << " d: " << density
          //           << " m: " << max_density
          //           << std::endl;
          if(max_density < density) {
            max_density = density;
            max_water = water;
            max_suger = suger;
          }
        }
      }
    }
  }

  std::cout << (max_water + max_suger) << " " << max_suger << std::endl;
  return 0;
}
