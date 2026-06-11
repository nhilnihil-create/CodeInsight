#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void MAIN() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (u == 1) a[v]++;
    if (v == n) a[u]++;
  }
  for (int i = 2; i < n; i++) {
    if (a[i] == 2) {
      cout << "POSSIBLE" << '\n';
      return;
    }
  }
  cout << "IMPOSSIBLE" << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
