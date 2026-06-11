#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> used(m, 1);
  vector<vector<int>> in(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> in[i][j];
      in[i][j]--;
    }
  }
  int ans = 1 << 30;
  for (int d = 0; d < m; d++) {
    vector<int> cnt(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (used[in[i][j]]) {
          cnt[in[i][j]]++;
          break;
        }
      }
    }
    int s = 0, t = 0;
    for (int i = 0; i < m; i++) {
      if (cnt[i] > t) {
        s = i;
        t = cnt[i];
      }
    }
    used[s] = 0;
    ans = min(ans, t);
  }
  cout << ans << endl;
  return 0;	
}