#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve() {
  int a, b;
  cin >> a >> b;
  if (abs(a - b) > 1) {
    cout << 0 << '\n';
    return;
  }
  int ans = 1;
  for (int i = 1; i <= a; i++) {
    (ans *= i) %= MOD;
  }
  for (int i = 1; i <= b; i++) {
    (ans *= i) %= MOD;
  }
  if (a == b) (ans *= 2) %= MOD;
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
