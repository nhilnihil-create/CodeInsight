#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int x, a, b;
  cin >> x >> a >> b;
  int t = b - a;
  if (t <= 0) cout << "delicious" << '\n';
  else if (t <= x) cout << "safe" << '\n';
  else cout << "dangerous" << '\n';
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
