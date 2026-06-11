#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  string s;
  cin >> s;

  string ans;
  for (int i = 0; i < s.length(); i++) {
    char c = s.at(i);
    switch (c) {
      case '0':
        ans += c;
        break;
      case '1':
        ans += c;
        break;
      case 'B':
        if (ans.length() > 0) ans = ans.substr(0, ans.length() - 1);
        break;
      default:
        break;
    }
  }

  cout << ans << endl;
}
