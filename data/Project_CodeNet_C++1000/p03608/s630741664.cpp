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
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> targets(R);
  for (int i = 0; i < R; i++) {
    cin >> targets[i];
    targets[i]--;
  }
  vector<vector<int>> D(N, vector<int>(N, 1e9 + 5));
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    D[a][b] = c;
    D[b][a] = c;
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        chmin(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }
  sort(targets.begin(), targets.end());
  int ans = 1e9 + 10;
  do {
    int d = 0;
    for (int i = 0; i < R - 1; i++) {
      d += D[targets[i]][targets[i + 1]];
    }
    chmin(ans, d);
  } while (next_permutation(targets.begin(), targets.end()));

  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
