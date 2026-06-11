#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ii> a(n), b(m);
  for (auto &i : a) {
    cin >> i.fi >> i.sc;
  }
  for (auto &j : b) {
    cin >> j.fi >> j.sc;
  }
  auto f = [](ii a, ii b) {
    return abs(a.fi - b.fi) + abs(a.sc - b.sc);
  };
  for (auto &i : a) {
    int ans = 0;
    for (int j = 1; j < m; j++) {
      if (f(i, b[j]) < f(i, b[ans])) {
        ans = j;
      }
    }
    cout << ans + 1 << '\n';
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
