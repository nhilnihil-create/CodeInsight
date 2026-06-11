#include <bits/stdc++.h>

using namespace std;

template <class T> inline bool chmin(T &a, T b) { /* {{{ */
  if (a > b) {
    a = b;
    return true;
  }
  return false;
} /* }}} */

int main() {
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i];
  }
  const int inf = 1e9 + 5;
  vector<vector<int>> D(450, vector<int>(450, inf));
  D[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int a = 400; a >= 0; a--) {
      for (int b = 400; b >= 0; b--) {
        if (D[a][b] == inf) continue;
        chmin(D[a + A[i]][b + B[i]], D[a][b] + C[i]);
      }
    }
  }
  int ans = inf;
  for (int a = 1; a <= 400; a++) {
    for (int b = 1; b <= 400; b++) {
      if (a * Mb == b * Ma) chmin(ans, D[a][b]);
    }
  }
  if (ans == inf) ans = -1;
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
