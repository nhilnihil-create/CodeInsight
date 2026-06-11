#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, ans = 0, n, max = 0, a;
  scanf("%lld", &n);
  for(i = 0; i < n; ++i) {
    scanf("%lld", &a);
    ll t = (a - 1) / (max + 1);
    ans += t;
    if(!max) max = 1;
    if(!t && max < a) max = a;
  }
  printf("%lld", ans);
  return 0;
}