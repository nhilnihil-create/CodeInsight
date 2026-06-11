#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a, b, c;
  cin >> a >> b >> c;
  int az = (int) a.size();
  bool f = (a[az -1] == b[0]);
  int bz = (int) b.size();
  bool ff = (b[bz - 1] == c[0]);
  if(ff && f) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
