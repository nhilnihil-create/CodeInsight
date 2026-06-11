#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  A *= 100;
  B *= 100;

  int mx_sugar_water = A;
  int mx_sugar = 0;
  for(int a=0; a <= F/A; a++) {
    for(int b=0; b <= F/B; b++) {
      int water = a*A + b*B;
      if (water > F) break;

      int limit = water / 100 * E;
      limit = std::min(limit, F - water);

      for(int c=0; c <= limit/C; c++) {
        for(int d=0; d <= limit/D; d++) {
          int sugar = c*C + d*D;

          if (sugar > limit) break;

          if (water+sugar == 0) continue;

          if (mx_sugar * (sugar+water) < mx_sugar_water * sugar) {
            mx_sugar_water = water + sugar;
            mx_sugar = sugar;
          }
        }
      }
    }
  }

  cout << mx_sugar_water << " " << mx_sugar << endl;

  return 0;
}
