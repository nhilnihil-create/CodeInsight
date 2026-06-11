#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n, avr;
  cin >> n >> avr;
  vector<map<int, int>> m(n + 1);
  m[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    t -= avr;
    for (int j = -2500; j <= 2500; j++) {
      m[i][j] = m[i - 1][j - t] + m[i - 1][j];
    }
  }
  cout << m[n][0] - 1 << '\n';
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
