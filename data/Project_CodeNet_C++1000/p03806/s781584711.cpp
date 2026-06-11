#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void solve() {
  vector<vector<int>> f(401, vector<int>(401, 2e9));
  f[0][0] = 0;
  int n, ma, mb;
  cin >> n >> ma >> mb;
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    for (int j = 400; j >= a; j--)
    for (int k = 400; k >= b; k--) {
      chmin(f[j][k], f[j - a][k - b] + c);
    }
  }
  int ans = 2e9;
  for (int i = 1; ma * i <= 400 && mb * i <= 400; i++) {
    chmin(ans, f[ma * i][mb * i]);
  }
  if (ans == 2e9) ans = -1;
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
