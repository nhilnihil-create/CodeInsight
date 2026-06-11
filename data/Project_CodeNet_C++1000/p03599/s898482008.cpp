#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  set<int> water, sugar;
  for (int i = 0; i <= f; i++) {
    for (int j = 0; j <= f; j++) {
      int w = 100 * a * i + 100 * b * j;
      if (w > f) {
        continue;
      }
      water.insert(w);
    }
  }
  for (int i = 0; i <= f; i++) {
    for (int j = 0; j <= f; j++) {
      int s = c * i + d * j;
      if (s > f) {
        continue;
      }
      sugar.insert(s);
    }
  }

  int ans_w = 100 * a, ans_s = 0;
  for (auto it = water.begin(); it != water.end(); it++) {
    for (auto it2 = sugar.begin(); it2 != sugar.end(); it2++) {
      int w = *it, s = *it2;
      if (w + s > f) {
        continue;
      }
      if (s * 100 > e * w) {
        continue;
      }
      if (ans_s * (s + w) < s * (ans_w + ans_s)) {
        ans_w = w;
        ans_s = s;
      }
    }
  }
  cout << ans_w + ans_s << " " << ans_s << endl;
  return 0;
}