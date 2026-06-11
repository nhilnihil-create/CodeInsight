#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, ans = "";
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    switch (s[i]) {
      case '0':
        ans.push_back('0');
        break;
      case '1':
        ans.push_back('1');
        break;
      case 'B':
        if (ans.size() == 0) break;
        ans.pop_back();
        break;
    }
  }
  cout << ans << endl;
}