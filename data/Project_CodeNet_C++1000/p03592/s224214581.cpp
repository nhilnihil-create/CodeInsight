#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 0) {
    cout << "Yes" << '\n';
    return;
  }
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++) {
    if (i * j + (n - i) * (m - j) == k) {
      cout << "Yes" << '\n';
      return;
    }
  }
  cout << "No" << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
