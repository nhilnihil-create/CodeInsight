#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> to(26, n + 1);
  vector<int> dp(n + 2), way(n + 2), alpha(n + 2);
  for (int i = n; i >= 0; i--) {
    dp[i] = n + 10;
    for (int c = 0; c < 26; c++) {
      int nx = to[c]; 
      if (1 + dp[nx] < dp[i]) {
        dp[i] = 1 + dp[nx];
        way[i] = nx;
        alpha[i] = c;
      }
    }
    if (i > 0) {
      to[int(s[i - 1] - 'a')] = i;
    }
  }
  string ans;
  int p = 0;
  while (p != n + 1) {
    ans += char(alpha[p] + 'a');
    p = way[p];
  }
  cout << ans << '\n';
  return 0;
}
