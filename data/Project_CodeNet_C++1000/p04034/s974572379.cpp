#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  int n, m; cin >> n >> m;
  vector<int> a(n + 1, 1), d(n + 1);
  d[1] = 1;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (d[u]) d[v] = 1;
    a[u]--;
    a[v]++;
    if (a[u] == 0) d[u] = 0;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (d[i]) ans++;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
