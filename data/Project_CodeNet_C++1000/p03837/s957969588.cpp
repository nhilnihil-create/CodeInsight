#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  // d[i][j]: i-jの最短距離
  // next[i][j]: i-jの最短経路中のiの次の点
  // indeces[i][j]: i-jを直接つなぐ辺のインデックス
  vector<vector<int>> d(n, vector<int>(n, -1)), next(n, vector<int>(n, -1)),
      indeces(n, vector<int>(n, -1));
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    d[a][b] = c;
    d[b][a] = c;
    next[a][b] = b;
    next[b][a] = a;
    indeces[a][b] = i;
    indeces[b][a] = i;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (d[j][i] < 0 || d[i][k] < 0) {
          continue;
        }

        int new_dist = d[j][i] + d[i][k];
        if (d[j][k] < 0 || new_dist < d[j][k]) {
          d[j][k] = new_dist;
          next[j][k] = next[j][i];
        }
      }
    }
  }

  vector<bool> used(m, false);
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      // i-jの最短経路を復元
      int cur = i;
      while (cur != j) {
        if (indeces[cur][next[cur][j]] != -1) {
          used[indeces[cur][next[cur][j]]] = true;
        }
        cur = next[cur][j];
      }
    }
  }

  cout << count(used.begin(), used.end(), false) << '\n';
}