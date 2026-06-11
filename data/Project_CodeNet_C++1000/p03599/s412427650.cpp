#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int maxAll = 0, maxSugar = 0;
  double minDist = 2.0;
  double LIMIT = (double)e / (100 + e);
  for (int i = 0; 100 * a * i <= f; i++) {
    int massA = 100 * a * i;
    for (int j = 0; 100 * b * j <= f - massA; j++) {
      int massB = 100 * b * j;
      for (int k = 0; c * k <= f - massA - massB; k++) {
        int massC = c * k;
        for (int l = 0; d * l <= f - massA - massB - massC; l++) {
          int massD = d * l;
          if (massA + massB + massC + massD <= 0) break;
          double conce =
              (double)(massC + massD) / (massA + massB + massC + massD);
          double dist = LIMIT - conce;
          if (dist >= 0 && dist < minDist) {
            minDist = dist;
            maxAll = massA + massB + massC + massD;
            maxSugar = massC + massD;
          }
        }
      }
    }
  }
  cout << maxAll << " " << maxSugar << endl;
  return 0;
}