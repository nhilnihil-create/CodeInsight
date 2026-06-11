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
  map<int, int> m;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    m[a] += b;
  }
  for (auto &i : m) {
    k -= i.sc;
    if (k <= 0) {
      cout << i.fi << '\n';
      return;
    }
  }
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
