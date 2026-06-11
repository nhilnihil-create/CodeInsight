#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, ans;
  cin >> s;
  for (char c : s) {
    if (c == '0') {
      ans += '0';
    } else if (c == '1') {
      ans += '1';
    } else if (ans != "") {
      ans.pop_back();
    }
  }
  cout << ans << '\n';
  return 0;
}