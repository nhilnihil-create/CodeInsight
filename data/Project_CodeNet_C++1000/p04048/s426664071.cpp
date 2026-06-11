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

long long gcd(long long x, long long y) {
  return y == 0 ? x : gcd(y, x % y);
}

int main() {
  long long n, x;
  scanf("%lld%lld", &n, &x);
  printf("%lld\n", (n - gcd(n, x)) * 3);
  return 0;
}
