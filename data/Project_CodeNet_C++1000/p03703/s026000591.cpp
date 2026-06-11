#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, n, k, ans = 0, now;
  scanf("%lld%lld", &n, &k);
  ll a[n], sum[n + 1];
  set<ll> s;
  set<ll>::iterator it;
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]), a[i] -= k;
  sum[0] = 0;
  s.insert(0);
  for(i = 0; i < n; ++i) sum[i + 1] = sum[i] + a[i], s.insert(sum[i + 1]);
  ll m = s.size(), num[m], sm = 1;
  for(it = s.begin(), i = 0; i < m; ++i, ++it) num[i] = *it;
  while(sm < m) sm <<= 1;
  ll seg[sm * 2];
  for(i = 1; i < sm * 2; ++i) seg[i] = 0;
  for(i = n; i >= 0; --i) {
    now = lower_bound(num, num + m, sum[i]) - num + sm;
    do {
      while(!(now & 1)) now >>= 1;
      ans += seg[now];
      ++now;
    } while((now & -now) != now);
    now = lower_bound(num, num + m, sum[i]) - num + sm;
    while(now) seg[now]++, now >>= 1;
  }
  printf("%lld", ans);
  return 0;
}