#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  map<int, int> m;
  for (int i = 2; i <= n; i++) {
    int tmp = i;
    for (int j = 2; j * j <= tmp; j++) {
      if (tmp % j == 0) {
        int cnt = 0;
        while (tmp % j == 0) {
          tmp /= j;
          cnt++;
        }
        m[j] += cnt;
      }
    }
    if (tmp > 1) m[tmp] += 1;
  }
  int ans = 1;
  for (auto &i : m) {
    (ans *= i.sc + 1) %= MOD;
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
