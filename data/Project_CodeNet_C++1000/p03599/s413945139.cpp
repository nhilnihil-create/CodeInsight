#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  pair<int, int> ans = make_pair(0, 0);
  for (int a = 0; a * A * 100 <= F; a++) {
    for (int b = 0; b * B * 100 <= F - a * A * 100; b++) {
      for (int c = 0; c * C <= F - a * A * 100 - b * B * 100; c++) {
        for (int d = 0; d * D <= F - a * A * 100 - b * B * 100 - c * C; d++) {
          if ((a * A * 100 + b * B * 100) * E < 100 * (c * C + d * D)) continue;
          if ((a * A * 100 + b * B * 100 + c * C + d * D) * ans.second
              <= ans.first * (c * C + d * D)) {
            ans = make_pair(a * A * 100 + b * B * 100 + c * C + d * D,
                            c * C + d * D);
          }
        }
      }
    }
  }
  cout << ans.first << " " << ans.second << '\n';
  return 0;
}
