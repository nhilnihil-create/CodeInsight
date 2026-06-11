#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 0, inf = 0;
  map<int, map<int, map<int, int>>> m;
  while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
    int ta = b / 2 + c / 2;
    int tb = a / 2 + c / 2;
    int tc = b / 2 + a / 2;
    a = ta;
    b = tb;
    c = tc;
    if (m[a][b][c]) {
      inf = 1;
      break;
    }
    m[a][b][c] = 1;
    ans++;
  }
  if (inf) cout << -1 << '\n';
  else cout << ans << '\n';
}
