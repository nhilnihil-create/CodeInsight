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
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 2; i < s.size(); i += 2) {
    if (s.substr(0, i / 2) == s.substr(i - i / 2, i / 2)) {
      ans = i;
    }
  }
  cout << ans << '\n';
}
