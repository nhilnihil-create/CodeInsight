#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  vector<int> a(13);
  a[4] = a[6] = a[9] = a[11] = 1;
  a[2] = 3;
  int x, y;
  cin >> x >> y;
  if (a[x] == a[y]) cout << "Yes" << '\n';
  else cout << "No" << '\n';
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
