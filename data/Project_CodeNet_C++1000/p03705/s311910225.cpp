#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int sum(int l, int r) {
  int n = r - l + 1;
  return (l + r) * n / 2;
}

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << max(((n - 1) * b + a) - ((n - 1) * a + b) + 1, 0LL) << '\n';
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
