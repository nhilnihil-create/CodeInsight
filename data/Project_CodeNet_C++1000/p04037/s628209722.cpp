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
  for (int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  std::sort(a + 1, a + n + 1, std::greater<int>());
  
  for (int i = 1; i <= n; ++i)
    if (i >= a[i + 1]) {
      bool ans = 0;
      for (int j = i + 1; a[j] == i; ++j)
        ans ^= 1;
      ans |= ((a[i] - i + 1) & 1) == 0;
      printf(ans ? "First\n" : "Second\n");
      break;
    }
  return 0;
}
