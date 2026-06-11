#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  vector<pair<ll, int> > vt;
  for (int i = 0; i < n; i++) {
    int v; cin >> v; vt.push_back({v, 0});
  }
  for (int i = 0; i < m; i++) {
    int v; cin >> v; vt.push_back({v, 1});
  }
  sort(all(vt));
  int horyzontal = 0, vertical = 0;
  ll ans = 0;
  for (auto x : vt) {
    if (x.second == 0) { // vertical
      ans += x.first * (m + 1 - horyzontal);
      vertical++;
    }
    else {
      ans += x.first * (n + 1 - vertical);
      horyzontal++;
    }
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
