// by newbiechd
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

// DELETE the debugging information!
#define debug(x) std::cerr << #x << " = " << (x) << std::endl

const int N_MAX = 100003;
bool f[N_MAX];
int cnt[N_MAX];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  f[1] = 1;
  for (int i = 1; i <= n; ++i)
    cnt[i] = 1;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    f[y] |= f[x];
    if (--cnt[x] == 0)
      f[x] = 0;
    ++cnt[y];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += f[i];
  printf("%d\n", ans);
  return 0;
}
