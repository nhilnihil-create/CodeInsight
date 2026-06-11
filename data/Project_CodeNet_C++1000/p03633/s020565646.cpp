// I love
// Chemise Blanche

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << __LINE__ << " > " << #x << " = " << (x) << endl

int lcm(int a, int b) {
  return a / __gcd(a, b) * b;
}

void MAIN() {
  int n; cin >> n;
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    int t; cin >> t;
    ans = lcm(ans, t);
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
