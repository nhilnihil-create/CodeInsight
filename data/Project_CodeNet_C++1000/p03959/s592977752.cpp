#include <stdio.h>
#define mod 1000000007
typedef long long ll;

int main(void) {
  ll i, j, n, ans = 1;
  scanf("%lld", &n);
  ll t[n], a[n];
  bool bt[n], ba[n];
  for(i = 0; i < n; ++i) scanf("%lld", &t[i]), bt[i] = false;
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]), ba[i] = false;
  bt[0] = ba[n - 1] = true;
  for(i = 1; i < n; ++i) if(t[i] != t[i - 1]) bt[i] = true;
  for(i = n - 2; i >= 0; --i) if(a[i] != a[i + 1]) ba[i] = true;
  for(i = 0; i < n; ++i) {
    if(bt[i] && ba[i]) {
      if(a[i] != t[i]) ans = 0;
    } else if(bt[i]) {
      if(t[i] > a[i]) ans = 0;
    } else if(ba[i]) {
      if(a[i] > t[i]) ans = 0;
    } else {
      ans *= a[i] < t[i] ? a[i] : t[i];
    }
    ans %= mod;
  }
  printf("%lld", ans);
  return 0;
}