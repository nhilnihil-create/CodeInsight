#include <stdio.h>
#include <algorithm>
#include <utility>
typedef long long ll;
using namespace std;

int main(void) {
  ll i, j, k, n, now, ans = 0, tmp, r = 1;
  scanf("%lld%lld", &n, &k);
  ll a[n], b[n];
  now = k;
  for(i = 0; i < n; ++i) scanf("%lld%lld", &a[i], &b[i]);
  while( 1 ) {
    tmp = 0;
    for(i = 0; i < n; ++i) if((now | a[i]) == now) tmp += b[i];
    if(ans < tmp) ans = tmp;
    while(!(r & now) && r <= k) now += r, r <<= 1;
    now -= r;
    if(r > k) break;
  }
  printf("%lld", ans);
  return 0;
}