#include <bits/stdc++.h>


using namespace std;

char s[200002];
int n, nxt[200002][26], dp[200002];
string ans;

int main()
{
  cin >> (s + 1);
  n = strlen(s + 1);
  dp[n + 1] = 1;
  for (int i = 0; i < 26; i++)
    nxt[n + 1][i] = n + 1;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < 26; j++)
      nxt[i][j] = nxt[i + 1][j];
    nxt[i][s[i] - 'a'] = i;
  }
  for (int i = n; i >= 1; i--) {
    bool ok = 0;
    dp[i] = n + 2;
    for (int j = 0; j < 26; j++) {
      if (nxt[i][j] != n + 1)
        dp[i] = min(dp[i], dp[nxt[i][j] + 1] + 1);
      else
        ok = 1;
    }
    if (ok)
      dp[i] = 1;
  }
  int i = 1;
  while (i <= n) {
    bool ok = 0;
    int l = -1, poz;
    for (int j = 0; j < 26; j++) {
      if (nxt[i][j] != n + 1) {
        if (l == -1 && dp[i] == dp[nxt[i][j] + 1] + 1) {
          l = j;
          poz = nxt[i][j] + 1;
        }
      }
      else {
        ok = 1;
        l = j;
        break;
      }
    }
    cout << (char)(l + 'a');
    if (ok)
      break;
    i = poz;
  }
  return 0;
}
