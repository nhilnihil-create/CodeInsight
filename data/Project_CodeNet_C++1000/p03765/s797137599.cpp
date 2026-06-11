#include <stdio.h>
#include <string.h>
typedef long long ll;

int main(void) {
  ll i, n, m, q, a, b, c, d;
  char s[100010], t[100010];
  scanf("%s%s%lld", s, t, &q);
  n = strlen(s), m = strlen(t);
  ll sums[n + 1], sumt[m + 1];
  sums[0] = sumt[0] = 0;
  for(i = 0; i < n; ++i) sums[i + 1] = sums[i] + (s[i] == 'A' ? 1 : 2);
  for(i = 0; i < m; ++i) sumt[i + 1] = sumt[i] + (t[i] == 'A' ? 1 : 2);
  for(i = 0; i < q; ++i) {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    if((sums[b] - sums[--a]) % 3 == (sumt[d] - sumt[--c]) % 3) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}