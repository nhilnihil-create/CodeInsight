#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  int l; cin >> l;
  int j = n - 1;

  vector<vector<int>> go(20, vector<int>(n, -1));
  for (int i = n - 1; i >= 0; --i) {
    while (v[j] - v[i] > l) --j;
    go[0][i] = j;
    for (int k = 0; k < 19; ++k) {
      int nxt = go[k][i];
      if (nxt != -1)
        go[k + 1][i] = go[k][nxt];
    }
  }

  int q; cin >> q;
  while (q--) {
    int a, b; cin >> a >> b; --a; --b;
    if (a > b) swap(a, b);

    int ans = 1;
    for (int k = 19; k >= 0; --k) {
      if (go[k][a] == -1) continue;
      if (go[k][a] < b) {
        ans += (1 << k);
        a = go[k][a];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
