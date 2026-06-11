#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
const int N = 2e5 + 5;
char s[N];
int dp[N], nxt[N][26];
 
int main() {
  scanf("%s", s);
  int n = strlen(s);
 
  dp[n] = 1;
  for (int i = 0; i < 26; ++i) nxt[n][i] = n;
  for (int i = n - 1; i >= 0; --i) {
    dp[i] = 1e9;
    for (int j = 0; j < 26; ++j) {
      dp[i] = min(dp[i], dp[nxt[i + 1][j]] + 1);
      nxt[i][j] = nxt[i + 1][j];
    }
    nxt[i][s[i] - 'a'] = i;
  }
 
  int len = 1e9, pos, c;
  for(int i = 0; i < 26; ++i) {
    if (dp[nxt[0][i]] < len) {
      len = dp[nxt[0][i]]; 
      pos = nxt[0][i]; 
      c = i; 
    }
  }
 
  printf("%c", char('a' + c));
  while (pos < n) {
    --len;
    for (int i = 0; i < 26; ++i) {
      if (dp[nxt[pos + 1][i]] == len) {
        c = i;
        break;
      }
    }
    printf("%c", char('a' + c));
    pos = nxt[pos + 1][c];
  }
  puts("");
}
