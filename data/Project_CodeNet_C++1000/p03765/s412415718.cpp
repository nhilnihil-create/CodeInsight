/**
 *    author:  tourist
 *    created: 15.01.2020 15:11:38       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  vector<int> ps(s.size() + 1);
  for (int i = 0; i < (int) s.size(); i++) {
    ps[i + 1] = ps[i] + (s[i] == 'A' ? 1 : 2);
  }
  vector<int> pt(t.size() + 1);
  for (int i = 0; i < (int) t.size(); i++) {
    pt[i + 1] = pt[i] + (t[i] == 'A' ? 1 : 2);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = ps[b] - ps[a - 1];
    int y = pt[d] - pt[c - 1];
    cout << (x % 3 == y % 3 ? "YES" : "NO") << '\n';
  }
  return 0;
}
