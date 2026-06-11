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
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 1, old_mode = 0;
  for (int i = 0; i < n - 1; i++) {
    int cur_mode = 0; // a[i] == a[i + 1]
    if (a[i] < a[i + 1]) cur_mode = 1;
    if (a[i] > a[i + 1]) cur_mode = 2;
    if (cur_mode == 0) continue;
    if (old_mode == 0) {
      old_mode = cur_mode;
    }
    else if (old_mode != cur_mode) {
      ans++;
      old_mode = 0;
    }
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
