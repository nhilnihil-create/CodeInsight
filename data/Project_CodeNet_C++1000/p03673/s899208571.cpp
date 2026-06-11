#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n;
  cin >> n;
  deque<int> d;
  for (int i = 1; i <= n; i++) {
    int t; cin >> t;
    if (i % 2) d.push_back(t);
    else d.push_front(t);
  }
  if (n % 2) reverse(all(d));
  for (auto &i : d) cout << i << ' ';
  cout << '\n';
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
