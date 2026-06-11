#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

string S;
int n, nxt[N][26], f[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> S; n = S.length();
  f[n + 1] = 1;
  for (int j = 0; j < 26; ++j) nxt[n + 1][j] = n + 1;
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < 26; ++j) nxt[i][j] = nxt[i + 1][j];
    nxt[i][S[i - 1] - 'a'] = i;
    f[i] = 1e9;
    for (int j = 0; j < 26; ++j) {
      f[i] = min(f[i], f[nxt[i][j] + 1] + 1);
    }
  }
  int cur = 1;
  while (cur <= n) {
    for (int j = 0; j < 26; ++j) {
      if (f[cur] == f[nxt[cur][j] + 1] + 1) {
        cur = nxt[cur][j] + 1;
        cout << (char)('a' + j);
        break;
      }
    }
  }
  return 0;
}