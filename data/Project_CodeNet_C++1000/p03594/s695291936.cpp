#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const char mp[] = "RYGB";
int n, m, d;

int main() {
  scanf("%d %d %d", &n, &m, &d);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = (i + j + 505) / d;
      int y = (i - j + 505) / d;
      putchar(mp[(x & 1) << 1 | (y & 1)]);
    }
    putchar(10);
  }
  return 0;
}