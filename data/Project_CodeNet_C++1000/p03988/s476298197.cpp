#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, n, a;
  scanf("%lld", &n);
  ll cnt[n];
  for(i = 0; i < n; ++i) cnt[i] = 0;
  for(i = 0; i < n; ++i) scanf("%lld", &a), cnt[a]++;
  for(i = n - 1; !cnt[i]; --i);
  a = i;
  for(i = 0; i < (a + 1) / 2; ++i) if(cnt[i]) {
    printf("Impossible");
    return 0;
  }
  if(a & 1) {
    if(cnt[i] != 2) {
      printf("Impossible");
      return 0;
    }
  } else if(cnt[i] != 1) {
    printf("Impossible");
    return 0;
  }
  for(++i; i <= a; ++i) if(cnt[i] < 2) {
    printf("Impossible");
    return 0;
  }
  printf("Possible");
  return 0;
}