#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n, k;
  cin >> n >> k;
  int ans = 0, l = -1;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    ans += (t + k) - max(t, l);
    l = t + k;
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
