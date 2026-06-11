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
  int n, L;
  scanf("%d%d", &n, &L);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  for (int i = 1; i < n; ++i)
    if (a[i] + a[i + 1] >= L) {
      printf("Possible\n");
      for (int j = 1; j < i; ++j)
        printf("%d\n", j);
      for (int j = n - 1; j > i; --j)
        printf("%d\n", j);
      printf("%d\n", i);
      return 0;
    }
  printf("Impossible\n");
  return 0;
}
