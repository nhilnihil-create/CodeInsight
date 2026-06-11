#include <bits/stdc++.h>
using namespace std;

int ans[101][101];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w, n;
  cin >> h >> w >> n;
  vector < int > a(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  int k = 1;
  for (int i = 0; i < h; ++i) {
    if (i && ans[i - 1][0] != k) {
      for (int j = w - 1; j >= 0; --j) {
        if (!a[k]) 
          ++k;
        ans[i][j] = k;
        --a[k]; 
      }
    }
    else {
      for (int j = 0; j < w; ++j) {
        if (!a[k]) 
          ++k;
        ans[i][j] = k;
        --a[k]; 
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j)
      cout << ans[i][j] << ' ';
    cout << '\n';
  }
}