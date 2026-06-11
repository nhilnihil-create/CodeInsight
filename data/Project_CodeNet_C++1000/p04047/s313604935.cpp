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
int a[N_MAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n * 2; ++i)
    scanf("%d", a + i);
  std::sort(a + 1, a + n * 2 + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += std::min(a[i * 2 - 1], a[i * 2]);
  printf("%d\n", ans);
  return 0;
}
