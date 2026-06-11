#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s, t;
  int q;
  cin >> s >> t >> q;
  
  vector<int> x(s.size() + 1), y(t.size() + 1);
  for (int i = 1; i <= s.size(); i++) {
    if (s.at(i - 1) == 'A') x.at(i) = 1;
    else x.at(i) = 2;
    x.at(i) += x.at(i - 1);
  }
  for (int i = 1; i <= t.size(); i++) {
    if (t.at(i - 1) == 'A') y.at(i) = 1;
    else y.at(i) = 2;
    y.at(i) += y.at(i - 1);
  }
  
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((x.at(b) - x.at(a - 1)) % 3 == (y.at(d) - y.at(c - 1)) % 3) cout << "YES\n";
    else cout << "NO\n";
  }
}