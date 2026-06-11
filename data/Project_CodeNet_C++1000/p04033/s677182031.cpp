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

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a <= 0 && b >= 0) {
    printf("Zero\n");
    return 0;
  }
  if (a > 0) {
    printf("Positive\n");
    return 0;
  }
  printf(((b - a + 1) & 1) ? "Negative\n" : "Positive\n");
  return 0;
}
