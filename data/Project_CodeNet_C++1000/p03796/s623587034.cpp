#include <cstdio>
#define MOD 1000000007

int main() {
  int n;
  long long o = 1;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) o = o * i % MOD;
  printf("%lld\n", o);
}