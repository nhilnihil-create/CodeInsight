#include <stdio.h>
#include <vector>
typedef long long ll;

int main(void) {
  ll i, j, k, n, f[26], l[26], now = 26;
  char s[200010];
  std::vector<bool> ans[26][26];
  bool flg[26], b;
  scanf("%s", s);
  for(i = 0; i < 26; ++i) f[i] = l[i] = -1;
  for(i = 0; s[i]; ++i) {
    if(f[s[i] - 'a'] == -1) --now, f[s[i] - 'a'] = i;
    l[s[i] - 'a'] = i;
    if(!now) {
      for(j = 0; j < 26; ++j) for(k = 0; k < 26; ++k) {
        if(f[j] < l[k]) ans[j][k].push_back(false);
        else ans[j][k].push_back(true);
      }
      for(j = 0; j < 26; ++j) f[j] = l[j] = -1;
      now = 26;
    }
  }
  n = ans[0][0].size();
  if(n) for(i = 0; i < 26; ++i) if(f[i] != -1) for(j = 0; j < 26; ++j) ans[j][i][n - 1] = false;
  if(n) for(i = n - 1; i; --i) {
    for(j = 0; j < 26; ++j) {
      b = false;
      for(k = 0; k < 26; ++k) b = b | ans[j][k][i];
      if(!b) for(k = 0; k < 26; ++k) ans[k][j][i - 1] = false;
    }
  }
  for(i = 0; i < 26; ++i) flg[i] = true;
  for(i = 0; i < n; ++i) {
    for(j = 0; j < 26; ++j) if(flg[j]) {
      b = false;
      for(k = 0; k < 26; ++k) b = b | ans[j][k][i];
      if(b) {
        printf("%c", j + 'a');
        for(k = 0; k < 26; ++k) flg[k] = ans[j][k][i];
        break;
      }
    }
  }
  for(i = 0; i < 26; ++i) if(flg[i] && f[i] == -1) {
    printf("%c", i + 'a');
    break;
  }
  return 0;
}