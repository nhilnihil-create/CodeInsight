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
  int n, m;
  scanf("%d%d", &n, &m);
  int odd[2], cntOdd = 0;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
    if (a[i] & 1) {
      if (cntOdd > 1) {
        printf("Impossible\n");
        return 0;
      }
      odd[cntOdd] = i;
      ++cntOdd;
    }
  }
  if (m == 1) {
    if (n > 1)
      printf("%d\n2\n%d 1\n", n, n - 1);
    else
      printf("1\n1\n1\n");
    return 0;
  }
  if (m == 2) {
    if (a[1] > 1)
      printf("%d %d\n2\n%d %d\n", a[1], a[2], a[1] - 1, a[2] + 1);
    else
      printf("%d %d\n1\n%d\n", a[1], a[2], n);
    return 0;
  }
  
  if (cntOdd > 0) {
    std::swap(a[1], a[odd[0]]);
  }
  if (cntOdd > 1) {
    std::swap(a[m], a[odd[1]]);
  }
  for (int i = 1; i <= m; ++i)
    printf("%d ", a[i]);
  printf("\n%d\n", m - (a[1] == 1));
  if (a[1] > 1)
    printf("%d ", a[1] - 1);
  for (int i = 2; i < m; ++i)
    printf("%d ", a[i]);
  printf("%d\n", a[m] + 1);
  return 0;
}
