#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, n, m, now = 1, ans = 0, sm = 1, a, b, t, sum = 0, max = 0;
  scanf("%lld%lld", &n, &m);
  while(sm < m) sm <<= 1;
  ll seg[sm * 2 + 1], las[sm * 2];
  for(i = 1; i < sm * 2; ++i) {
    seg[i] = 0;
    if(i == now * 2) now <<= 1;
    las[i] = (i - now + 1) * sm / now;
  }
  scanf("%lld", &b);
  for(i = 1; i < n; ++i) {
    scanf("%lld", &a);
    ans += (a - b + m) % m;
    if((a - b + m) % m > 1) {
      t = (b + 1) % m;
      if(t < a) {
        now = t + sm;
        while( 1 ) {
          while(!(now & 1)) now >>= 1;
          while(las[now] > a) now <<= 1;
          seg[now]++;
          if(las[now] == a) break;
          now++;
        }
        if(a != m) seg[sm + a] -= a - t;
      } else {
        now = t + sm;
        while( 1 ) {
          while(!(now & 1)) now >>= 1;
          seg[now]++;
          if(las[now] == sm) break;
          now++;
        }
        seg[sm] += m + 1 - t;
        now = sm + 1;
        if(a != 1) while( 1 ) {
          while(!(now & 1)) now >>= 1;
          while(las[now] > a) now <<= 1;
          seg[now]++;
          if(las[now] == a) break;
          now++;
        }
        seg[sm + a] -= a - t + m;
      }
    }
    b = a;
  }
  for(i = 0; i < m; ++i) {
    now = i + sm;
    while(now) sum += seg[now], now >>= 1;
    if(sum > max) max = sum;
  }
  printf("%lld", ans - max);
  return 0;
}