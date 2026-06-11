#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6 + 1;

int n, nxt[26];
int tr[N], tnx[N][26];
int dp[N];
string s;

int32_t main() { cin.tie(0)->sync_with_stdio(0);
  cin >> s;
  n = s.size();
  s = ' ' + s;
  for (int i = 1; i <= n; i++) {
    s[i] -= 'a';
  }
  memset(dp, 0x3f, sizeof dp);
  memset(nxt, -1, sizeof nxt);
  dp[0] = 0;
  for (int i = n; i >= 1; i--) {
    nxt[s[i]] = i;
    for (int c = 0; c < 26; c++) {
      dp[i] = min(dp[i], dp[nxt[c] + 1] + 1);
      tnx[i][c] = nxt[c];
    }
    for (int c = 0; c < 26; c++) {
      if (dp[i] == dp[nxt[c] + 1] + 1) {
        tr[i] = c;
        break;
      }
    }
  }
  int mn = dp[1], i = 1;
  string ans;
  while (mn) {
    ans += tr[i] + 'a';
    i = tnx[i][tr[i]] + 1;
    mn = dp[i];
  }
  cout << ans;
}