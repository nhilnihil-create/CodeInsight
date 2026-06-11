#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n,rec[N][26],las[N][26],sta[26],cur[26];
char s[N];
void solve(int p) {
  if (p > n) return;
  for (int i = 0 ; i < 26 ; ++ i) {
    if (!las[p][i]) {
      cout << (char)(i + 'a');
      solve(rec[p][i]);
      return;
    }
  }
}
int main() {
  scanf("%s",s+1);
  n = strlen(s+1);
  for (int i = 0 ; i < 26 ; ++ i)
    sta[i] = n + 1;
  for (int i = n ; i >= 0 ; -- i) {
    for (int j = 0 ; j < 26 ; ++ j)
      las[i][j] = cur[j], rec[i][j] = sta[j];
    if (!i) break;
    cur[s[i] - 'a'] = i;
    sta[s[i] - 'a'] = i;
    int key = 1;
    for (int i = 0 ; i < 26 ; ++ i)
      key &= (cur[i] > 0);
    if (key) memset(cur,0,sizeof cur);
  }
  solve(0);
  cout << endl;
  return 0;
}
