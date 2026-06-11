#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  
  int wa, w, s, sw, ans_sw = 100 * A, ans_s = 0, limit, dmax;
  while (wa < F) {
    w = wa;
    while (w < F) {
      limit = min(w / 100 * E, F - w);
      dmax = limit / D;
      s = dmax * D;
      for (int i = 0; i <= dmax; i++) {
        s += (limit - s) / C * C;
        sw = w + s;
        if (s * ans_sw > ans_s * sw) {
          ans_sw = sw;
          ans_s = s;
        }
        s -= D;
      }
      w += 100 * B;
    }
    wa += 100 * A;
  }
  
  cout << ans_sw << " " << ans_s << endl;
}
