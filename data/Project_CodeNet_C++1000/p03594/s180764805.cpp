#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const char mp[] = "RYGB";
int n, m, d;

int get(int i, int j) {
  return (((j + 3) % 4 + 1) + ((i & 1) ? 0 : 2) + 3) % 4;
}

int main() {
  scanf("%d %d %d", &n, &m, &d);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = (i + j + 19260817) / d;
      int y = (i - j + 19260817) / d;
      putchar(mp[get(x, y)]);
    }
    putchar(10);
  }
  return 0;
}