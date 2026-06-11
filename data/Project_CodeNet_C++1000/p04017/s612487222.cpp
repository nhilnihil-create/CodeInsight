#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  
  int n, L, qq;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  cin >> L >> qq;

  const int K = 20;
  vector<vector<int>> next(n, vector<int>(K));
  for (int i = 0, j = 0; i < n; i++) {
    while (j + 1 < n && x[j + 1] - x[i] <= L) j++;
    next[i][0] = j;
  }
  for (int j = 1; j < K; j++) {
    for (int i = 0; i < n; i++) {
      next[i][j] = next[next[i][j - 1]][j - 1];
    }
  }

  while (qq--) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    if (a > b) swap(a, b);
    int ans = 0;
    for (int i = K - 1; i >= 0; i--) {
      if (next[a][i] < b) {
        a = next[a][i];
        ans += (1 << i);
      }
    }
    cout << ans + 1 << '\n';
  }

  return 0;
}
