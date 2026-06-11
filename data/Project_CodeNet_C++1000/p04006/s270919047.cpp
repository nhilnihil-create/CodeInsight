#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 2000;
ll a[N], mn[N];

void solve() {
  int n, x; cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mn[i] = 1e9;
  }
  ll ans = 1e18;
  for (int cnt = 0; cnt < n; cnt++) {
    for (int i = 0; i < n; i++) {
      int ni = (i - cnt + n) % n;
      mn[i] = min(mn[i], a[ni]);
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
      res += mn[i];
    }
    ans = min(ans, res + cnt * 1LL * x);
  }
  cout << ans;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
