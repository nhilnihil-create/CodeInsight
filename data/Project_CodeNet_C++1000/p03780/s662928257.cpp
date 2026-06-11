#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, n, ans, cnt;
  scanf("%lld%lld", &n, &k);
  ans = n;
  ll a[n];
  bool dpf[n + 1][k], dpb[n + 1][k];
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]);
  for(i = 0; i <= n; ++i) for(j = 0; j < k; ++j) dpf[i][j] = dpb[i][j] = false;
  dpf[0][0] = dpb[n][0] = true;
  for(i = 0; i < n; ++i) {
    for(j = 0; j < k; ++j) dpf[i + 1][j] = dpf[i][j];
    for(j = 0; j + a[i] < k; ++j) if(dpf[i][j]) dpf[i + 1][j + a[i]] = true;
  }
  for(i = n; i; --i) {
    for(j = 0; j < k; ++j) dpb[i - 1][j] = dpb[i][j];
    for(j = 0; j + a[i - 1] < k; ++j) if(dpb[i][j]) dpb[i - 1][j + a[i - 1]] = true;
  }
  for(i = 0; i < n; ++i) {
    if(a[i] > k) {
      ans--;
      continue;
    } else {
      cnt = 0;
      for(j = k - a[i]; j < k; ++j) cnt += dpb[i + 1][j] ? 1 : 0;
      if(cnt) {
        ans--;
        continue;
      }
      for(j = 1; j < k; ++j) {
        cnt -= dpb[i + 1][k - j] ? 1 : 0;
        if(k - j - a[i] >= 0) cnt += dpb[i + 1][k - j - a[i]] ? 1 : 0;
        if(dpf[i][j] && cnt) {
          ans--;
          break;
        }
      }
    }
  }
  printf("%lld", ans);
  return 0;
}