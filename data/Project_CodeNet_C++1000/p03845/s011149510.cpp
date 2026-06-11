#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    cout << ans - a[u] + v << '\n';
  }
}
