#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<vector<int>> v(26);
  for (int i = 0; i < n; i++) v[s[i] - 'a'].push_back(i);
  for (int i = 0; i < 26; i++) v[i].push_back(n);
  vector<int> dp(n + 1);
  dp[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    int mi = 1 << 30;
    for (int j = 0; j < 26; j++) {
      auto it = upper_bound(v[j].begin(), v[j].end(), i);
      mi = min(mi, dp[*it]);
    }
    dp[i] = mi + 1;
  }
  string ans;
  int cur = -1;
  while (cur < n) {
    int len = 1 << 30;
    char ch;
    int nxt;
    for (int i = 0; i < 26; i++) {
      auto it = upper_bound(v[i].begin(), v[i].end(), cur);
      if (dp[*it] < len) {
        len = dp[*it];
        nxt = *it;
        ch = i + 'a';
      }
    }
    cur = nxt;
    ans += ch;
  }
  cout << ans << endl;
  return 0;
}