#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s, ans = "";
  cin >> s;
  for (auto c : s) {
    if (c == 'B' && ans != "") {
      ans.pop_back();
      continue;
    } else if (c == 'B' && ans == "") continue;
    ans += c;
  }
  cout << ans << endl;
}