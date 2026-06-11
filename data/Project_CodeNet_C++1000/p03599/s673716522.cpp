#include<iostream>
#include<set>
using namespace std;

double conc(int water, int sugar) {
  double sum = water + sugar;
  return 100 * sugar / sum;
}

int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  set<int> water;
  set<int> sugar;

  for (int i = 0; i < F; i++) {
    for (int j = 0; j < F; j++) {
      int x = 100 * A * i + 100 * B * j;
      if (x <= F) water.insert(x);
    }
  }

  for (int i = 0; i < F; i++) {
    for (int j = 0; j < F; j++) {
      int y = C * i + D * j;
      if (y <= F) sugar.insert(y);
    }
  }

  double desired_conc = conc(100, E);
  double max_conc = 0;
  int ans_sum, ans_sugar;

  for (auto x : water) {
    for (auto y : sugar) {
      if (F < x + y) continue;
      double c = conc(x, y);
      if (max_conc <= c && c <= desired_conc) {
        max_conc = c;
        ans_sum = x + y;
        ans_sugar = y;
      }
    }
  }

  cout << ans_sum << ' ' << ans_sugar << endl;
  return 0;
}
