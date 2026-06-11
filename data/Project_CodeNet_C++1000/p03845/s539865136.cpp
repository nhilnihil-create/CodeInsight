#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, s = 0;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t.at(i);
    s += t.at(i);
  }
  cin >> m;
  vector<int> p(m), x(m);
  for (int i = 0; i < m; i++) {
    cin >> p.at(i) >> x.at(i);
    p.at(i)--;
    cout << s + x.at(i) - t.at(p.at(i)) << endl;
  }
}
