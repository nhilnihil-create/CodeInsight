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
int a[N_MAX], b[N_MAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  memcpy(b + 1, a + 1, sizeof(a[0]) * n);
  std::sort(b + 1, b + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    // debug(*std::lower_bound(b + 1, b + n + 1, a[i]));
    // debug(std::lower_bound(b + 1, b + n + 1, a[i]) - b);
    if (((std::lower_bound(b + 1, b + n + 1, a[i]) - b) & 1) == 0)
      ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
