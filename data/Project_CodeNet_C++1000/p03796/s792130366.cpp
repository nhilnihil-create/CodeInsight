#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    (ans *= i) %= (int)(1e9 + 7);
  }
  cout << ans << '\n';
  return 0;
}
