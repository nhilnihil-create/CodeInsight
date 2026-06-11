#include <bits/stdc++.h>
using namespace std;

int64_t calc(string s) {
  int64_t ans = 0, tmp = 0;

  for (char c : s) {
    if (c == '+') {
      ans += tmp;
      tmp = 0;
    } else {
      tmp = tmp * 10 + c - '0';
    }
  }
  ans += tmp;

  // cout << s << "=" << ans << endl;
  return ans;
}

int64_t dfs(string s, int x, string &S) {
  if (x == (int)S.size()) return calc(s);
  if (x > 0)
    return dfs(s + "+" + S.at(x), x + 1, S) + dfs(s + S.at(x), x + 1, S);

  // x == 0
  return dfs(s + S.at(x), x + 1, S);
}

int main() {
  string S;
  cin >> S;

  cout << dfs("", 0, S) << endl;
  return 0;
}
