#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    m[t]++;
  }
  if (n % 2 == 0 && m[0] != 0) {
    cout << 0 << '\n';
    return;
  }
  if (n % 2 == 1 && m[0] != 1) {
    cout << 0 << '\n';
    return;
  }
  int ans = 1;
  for (auto &i : m) {
    if (i.fi == 0) continue;
    if (i.sc != 2) {
      cout << 0 << '\n';
      return;
    }
    (ans *= 2) %= MOD;
  }
  cout << ans << '\n';
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
