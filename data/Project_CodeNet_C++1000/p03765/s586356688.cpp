#include<bits/stdc++.h>
using namespace std;

signed main() {
  string s, t;
  cin >> s >> t;
 
  static int cs[101010], ct[101010];
  cs[0] = ct[0] = 0;
  for (int i = 1; i <= s.size(); i++) {
    cs[i] += cs[i - 1];
    if (s[i - 1] == 'A') {
      cs[i] += 2;
    } else {
      cs[i]++;
    }
    cs[i] %= 3;
  }
 
  for (int i = 1; i <= t.size(); i++) {
    ct[i] += ct[i - 1];
    if (t[i - 1] == 'A') {
      ct[i] += 2;
    } else {
      ct[i]++;
    }
    ct[i] %= 3;
  }
 
  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((cs[b] - cs[a - 1] + 3) % 3 == (ct[d] - ct[c - 1] + 3) % 3) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
 
  return 0;
}