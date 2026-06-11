#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  string s;
  cin >> s;
  cout << s.substr(0, 4) << " " << s.substr(4, s.size() - 4) << endl;

  return 0;
}
