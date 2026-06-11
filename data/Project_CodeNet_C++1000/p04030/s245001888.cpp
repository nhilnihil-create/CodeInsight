#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  string s, ans;
  cin >> s;
  rep(i, 0, s.size()) {
    if (s[i] == '0') {
      ans += "0";
    } else if (s[i] == '1') {
      ans += "1";
    } else {
      if (!ans.empty()) {
        ans.pop_back();
      }
    }
  }
  cout << ans << endl;
  getchar();
}