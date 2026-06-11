#include <bits/stdc++.h>
using namespace std;

int main() {

  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  A = 100 * A;
  B = 100 * B;
  
  double rate = 0;
  int answerWater = 0;
  int answerSuger = 0;
  
  for (int i = 0; i <= F; i++) {
    for (int j = 0; j <= F - i; j++) {
      int water = A * i + B * j;
      if (F < water) {
        continue;
      }
      for (int k = 0; k <= F; k++) {
        for (int l = 0; l <= F - k; l++) {
          int suger = C * k + D * l;
          if ((water * E) < (suger * 100)) {
            continue;
          }
          int sugerWater = water + suger;
          if (F < sugerWater) {
            continue;
          }
          double rate_ = (double) suger / sugerWater * 100;
          if (rate <= rate_) {
            rate = rate_;
            answerWater = sugerWater;
            answerSuger = suger;
          }
        }
      }
    }
  }

  cout << answerWater << " " << answerSuger << endl;

  return 0;

}