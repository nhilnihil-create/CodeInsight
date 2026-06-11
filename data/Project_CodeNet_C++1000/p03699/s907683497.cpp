#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

#define oo LLONG_MAX

void solve() {
  int n;
  cin >> n;
  int l = oo, s = 0;
  for (int i = 1; i <= n; i++) {
    int t; cin >> t;
    s += t;
    if (t % 10) l = min(l, t);
  }
  if (s % 10 == 0 && l != oo) s -= l;
  if (s % 10 == 0) cout << 0 << '\n';
  else cout << s << '\n';
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
