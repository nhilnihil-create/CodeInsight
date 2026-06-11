#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int x;
  cin >> x;
  int ans = x / (5 + 6) * 2;
  x %= 5 + 6;
  if (x > 0) {
    ans++;
    x -= 6;
  }
  if (x > 0) {
    ans++;
    x -= 5;
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
