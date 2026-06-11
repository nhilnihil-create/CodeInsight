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
  if (m / 2 <= n) {
    cout << m / 2 << '\n';
    return;
  }
  int r = (m - 2 * n) / 2;
  if (r % 2) r--;
  n += r / 2;
  m -= r;
  cout << min(n, m / 2) << '\n';
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
