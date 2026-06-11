#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

signed main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL

  int n, k; cin >> n >> k;
  int g = 0, mx = 0;
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    g = __gcd(g, a);
    mx = max(mx, a);
  }
  if (k <= mx && k % g == 0) cout << "POSSIBLE";
  else cout << "IMPOSSIBLE";
}
