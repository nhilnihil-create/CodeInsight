#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const char mp[] = "RYGB";
const int maxn = 1505;
int n, m, d, ans[maxn][maxn];

int main() {
  scanf("%d %d %d", &n, &m, &d);
  int tot = n + n + m;
  for (int i = 1; i <= tot; i++) {
    for (int j = 1; j <= tot; j++) {
      ans[i][j] = (((j - 1) % 4 + 1) + ((i & 1) ? 0 : 2) - 1) % 4;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = (i + j + m) / d;
      int y = (i - j + m) / d;
      putchar(mp[(x & 1) << 1 | (y & 1)]);
//      putchar(mp[ans[x][y]]);
    }
    putchar(10);
  }
  return 0;
}