// J'aime
// Chemise Blanche

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << __LINE__ << " > " << #x << " = " << (x) << endl

void MAIN() {
  int n, p;
  cin >> n >> p;
  vector<int> d(5001);
  d[0] = 1;
  for (int i = 1; i <= n; i++) {
    int t; cin >> t;
    for (int j = 5000; j >= t; j--) {
      d[j] += d[j - t];
    }
  }
  int ans = 0;
  for (int i = 0; i <= 5000; i++) {
    if (i % 2 == p) ans += d[i];
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
  while (T--) MAIN();
}
