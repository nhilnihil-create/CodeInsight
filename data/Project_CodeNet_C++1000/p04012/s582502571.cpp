#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<bool> v(26, false);
  rep(i, 0, s.size()) { v[s[i] - 'a'] = !v[s[i] - 'a']; }
  bool ans = true;
  for (auto b : v) {
    if (b) {
      ans = false;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  getchar();
}