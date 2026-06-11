#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 1e5;
const ll INF = 1e18;
ll vt[N];

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }
  ll pref = 2;
  ll ans = vt[0] - 1;
  for (int pos = 1; pos < n; pos++) {
    if (vt[pos] == pref) {
      pref++; continue;
    }
    int res = (vt[pos] - 1) / pref;
    if (res == 0) continue;
    ans += res;
  }
  cout << ans;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(2);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
