#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int a, b;
  cin >> a >> b;
  if (a == 1) a = 14;
  if (b == 1) b = 14;
  if (a > b) cout << "Alice" << '\n';
  else if (a < b) cout << "Bob" << '\n';
  else cout << "Draw" << '\n';
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
