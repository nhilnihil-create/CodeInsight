#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  string s;
  cin >> s;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      cout << i << ' ' << i + 1 << '\n';
      return;
    }
    if (i > 1 && s[i] == s[i - 2]) {
      cout << i - 1 << ' ' << i + 1 << '\n';
      return;
    }
  }
  cout << -1 << ' ' << -1 << '\n';
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
