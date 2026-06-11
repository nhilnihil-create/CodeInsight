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
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    m[t]++;
  }
  int s = 0;
  for (auto &i : m) {
    s += i.sc - 1;
  }
  int ans = s / 4 * 4;
  s %= 4;
  if (s >= 3) {
    s -= 2;
    ans += 2;
  }
  if (s != 0) {
    ans += 2;
  }
  cout << n - ans << '\n';
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
