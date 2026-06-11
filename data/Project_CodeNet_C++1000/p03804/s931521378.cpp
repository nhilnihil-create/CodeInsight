#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  for (int i = 0; i < n - m + 1; i++)
  for (int j = 0; j < n - m + 1; j++) {
    int f = 1;
    for (int k = 0; k < m; k++)
    for (int l = 0; l < m; l++) {
      if (b[k][l] != a[i + k][j + l]) {
        f = 0;
        break;
      }
    }
    if (f) {
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
