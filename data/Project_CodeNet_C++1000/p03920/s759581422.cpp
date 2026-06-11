#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, n, now = 0;
  scanf("%lld", &n);
  for(i = 1; ; ++i) {
    now += i;
    if(now >= n) {
      ll a = now - n;
      for(j = 1; j <= i; ++j) if(a != j) printf("%lld\n", j);
      return 0;
    }
  }
  return 0;
}