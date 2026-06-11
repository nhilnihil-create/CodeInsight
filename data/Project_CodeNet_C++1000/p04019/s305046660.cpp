#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  vector<bool> a(4, false);
  rep(i, s.size()) {
    if (s[i] == 'N') a[0] = true;
    if (s[i] == 'W') a[1] = true;
    if (s[i] == 'S') a[2] = true;
    if (s[i] == 'E') a[3] = true; 
  }
  bool home = true;
  if (a[0] && !a[2] || !a[0] && a[2] || a[1] && !a[3] || !a[1] && a[3]) home = false;
  if (home) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}