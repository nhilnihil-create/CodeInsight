#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void MAIN() {
  int n; cin >> n;
  map<int, int> m;
  for (int i = 1; i <= n; i++) {
    int t; cin >> t;
    m[t]++;
  }
  vector<ii> v;
  for (auto &i : m) {
    if (i.sc >= 2) v.push_back(ii(i.fi, i.sc));
  }
  sort(all(v), greater<ii>());
  if (v.empty()) {
    cout << 0 << '\n';
    return;
  }
  if (v[0].sc >= 4) {
    cout << v[0].fi * v[0].fi << '\n';
    return;
  }
  if (v.size() < 2) {
    cout << 0 << '\n';
    return;
  }
  cout << v[0].fi * v[1].fi << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
