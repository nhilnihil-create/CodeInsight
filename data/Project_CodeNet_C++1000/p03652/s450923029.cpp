#include <stdio.h>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, m, ans = 1e9, max, mn;
  scanf("%lld%lld", &n, &m);
  ll a[n][m], now[n], cnt[m];
  bool flg[m];
  for(i = 0; i < n; ++i) for(j = 0; j < m; ++j) scanf("%lld", &a[i][j]), a[i][j]--;
  for(i = 0; i < n; ++i) now[i] = 0;
  for(i = 0; i < m; ++i) flg[i] = false;
  for(i = 0; i < m; ++i) {
    for(j = 0; j < m; ++j) cnt[j] = 0;
    for(j = 0; j < n; ++j) cnt[a[j][now[j]]]++;
    max = 0;
    for(j = 0; j < m; ++j) if(max < cnt[j]) max = cnt[j], mn = j;
    if(ans > max) ans = max;
    flg[mn] = true;
    for(j = 0; j < n; ++j) for(; now[j] < m && flg[a[j][now[j]]]; ++now[j]);
  }
  printf("%lld", ans);
  return 0;
}