#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  vector<int> vw(f + 1, false);
  for (int i = 0; i < 31; ++i) {
    for (int j = 0; j < 31; ++j) {
      int w = 100 * i * a + 100 * j * b;
      if (w < vw.size()) {
        vw[w] = true;
      }
    }
  }

  vector<bool> vs(f + 1, false);
  for (int i = 0; i < 3001; ++i) {
    for (int j = 0; j < 3001; ++j) {
      int s = i * c + j * d;
      if (s < vs.size()) {
        vs[s] = true;
      }
    }
  }

  double ans = -1, ans_w = 0, ans_s = 0;
  for (int w = 100; w < vw.size(); w += 100) {
    for (int s = 0; s < vs.size(); s++) {
      if (!vw[w] || !vs[s]) {
        continue;
      }

      if (w + s > f || w / 100 * e < s) {
        continue;
      }

      double conc = (s * 100.0) / (w + s);
      if (conc > ans) {
        ans = conc;
        ans_w = w;
        ans_s = s;
      }
    }
  }

  cout << ans_s + ans_w << ' ' << ans_s << '\n';
}