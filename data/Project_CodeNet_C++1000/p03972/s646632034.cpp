#include <stdio.h>
#include <utility>
#include <algorithm>
#include <functional>
typedef long long ll;
using namespace std;

int main(void) {
  ll i, j, k, ans = 0, h, w, cnt[2];
  scanf("%lld%lld", &w, &h);
  cnt[0] = w, cnt[1] = h;
  pair<ll, ll> p[w + h];
  for(i = 0; i < w; ++i) scanf("%lld", &p[i].first), p[i].second = 0, ans += p[i].first * (h + 1);
  for(i = w; i < w + h; ++i) scanf("%lld", &p[i].first), p[i].second = 1, ans += p[i].first * (w + 1);
  sort(p, p + w + h, greater< pair<ll, ll> >());
  for(i = 0; i < w + h; ++i) {
    ans -= cnt[(p[i].second + 1) % 2] * p[i].first;
    cnt[p[i].second]--;
  }
  printf("%lld", ans);
  return 0;
}