#include <stdio.h>
typedef long long ll;

ll min(ll a, ll b) {
  return a < b ? a : b;
}

int main(void) {
  ll i, a[7];
  for(i = 0; i < 7; ++i) scanf("%lld", &a[i]);
  ll m = min(a[0], min(a[3], a[4]));
  if(m) {
    ll cnt = 0;
    if(a[0] & 1) cnt++;
    if(a[3] & 1) cnt++;
    if(a[4] & 1) cnt++;
    if(cnt == 2) a[0]--, a[3]--, a[4]--, cnt = 3;
    printf("%lld", a[0] / 2 * 2 + a[1] + a[3] / 2 * 2 + a[4] / 2 * 2 + (cnt > 1 ? cnt : 0));
  } else printf("%lld", a[0] / 2 * 2 + a[1] + a[3] / 2 * 2 + a[4] / 2 * 2);
  return 0;
}