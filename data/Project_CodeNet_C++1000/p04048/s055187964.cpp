#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long li;

li Solve(li a, li b) {
  if (a < b) swap(a, b);
  if (a == b) return a;
  li x = (a - 1) / b;
  return x * 2 * b + Solve(b, a - x * b);
}

int main(void) {
  li n, x;
  scanf("%lld %lld\n", &n, &x);
  li ans = n + Solve(x, n - x);
  printf("%lld\n" ,ans);
}
