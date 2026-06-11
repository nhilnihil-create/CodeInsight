#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int w, a, b;
  cin >> w >> a >> b;
  int la = a, ra = a + w;
  int lb = b, rb = b + w;
  if (lb > ra) cout << lb - ra << '\n';
  else if (rb < la) cout << la - rb << '\n';
  else cout << 0 << '\n';
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
