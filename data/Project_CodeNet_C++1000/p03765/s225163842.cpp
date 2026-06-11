#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
vector<int> doit (const string& s) {
  int n = (int) s.size();
  vector<int> res(n + 1);
  for (int i = 0; i < n; i++) {
    res[i + 1] = res[i] + s[i] - 'A' + 1;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  string s, t;
  cin >> s >> t;
  auto ss = doit(s);
  auto ts = doit(t);
  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((ss[b] - ss[a - 1]) % 3 == (ts[d] - ts[c - 1]) % 3) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}