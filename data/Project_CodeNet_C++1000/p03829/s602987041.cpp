#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> v(n);
  for (auto &i : v) {
    cin >> i;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans += min((v[i] - v[i - 1]) * a, b);
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
