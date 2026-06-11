#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  double max = 0.0;
  int water = 0;
  int sugar = 0;
  for (int ai = 0; 100 * a * ai <= f; ++ai) {
    for (int bi = 0; 100 * b * bi <= f; ++bi) {
      for (int ci = 0; c * ci <= f; ++ci) {
        for (int di = 0; d * di <= f; ++di) {
          // e / 100
          int x = c * ci + d * di;             // g
          int y = 100 * a * ai + 100 * b * bi; // g
          double noudo = (double)x / (x + y);
          if (noudo > max && x + y <= f && x <= y / 100 * e) {
            max = noudo;
            water = y;
            sugar = x;
          }
        }
      }
    }
  }
  if (sugar == 0) water = 100 * a;
  cout << water + sugar << " " << sugar << endl;

  return 0;
}