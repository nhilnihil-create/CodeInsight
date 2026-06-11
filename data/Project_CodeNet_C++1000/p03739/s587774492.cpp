#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int sol(vector<int> a, int n, int pos) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i) a[i] += a[i - 1];
    if (pos == 1 && a[i] <= 0) ans += 1 - a[i], a[i] = 1;
    if (pos == 0 && a[i] >= 0) ans += a[i] + 1, a[i] = -1;
    pos = 1 - pos;
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  cout << min(sol(a, n, 0), sol(a, n, 1)) << '\n';
}

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
