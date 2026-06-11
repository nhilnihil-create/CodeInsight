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
  
  for (int i = 0; i <= F / A; i++) {
    int F_ = F - (A * i);
    for (int j = 0; j <= F_ / B; j++) {
      int water = A * i + B * j;
      int suger_ = water * E / 100;
      for (int k = 0; k <= suger_ / C; k++) {
        int suger2_ = suger_ - (C * k);
        for (int l = 0; l <= suger2_ / D; l++) {
          int suger = C * k + D * l;
          if (suger_ < suger) {
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