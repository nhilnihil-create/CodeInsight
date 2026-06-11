#include <stdio.h>
#include <utility>
#include <algorithm>
typedef long long ll;
using namespace std;

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
  if(a.first > b.first) return true;
  if(a.first < b.first) return false;
  if(a.second < b.second) return true;
  return false;
}

int main(void) {
  ll i, j, k, n, cnt = 1, now = 0, max, sum = 0;
  scanf("%lld", &n);
  pair<ll, ll> a[n];
  ll ans[n];
  for(i = 0; i < n; ++i) {
    scanf("%lld", &a[i].first);
    a[i].second = i;
    ans[i] = 0;
  }
  sort(a, a + n, cmp);
  now = a[0].second, max = sum = a[0].first;
  for(i = 1; i < n; ++i) {
    if(now > a[i].second) {
      ans[now] = sum - cnt * a[i].first + (i - cnt) * (max - a[i].first);
      now = a[i].second, cnt = 1, max = sum = a[i].first;
    } else sum += a[i].first, cnt++;
  }
  ans[now] = sum + (n - cnt) * max;
  for(i = 0; i < n; ++i) printf("%lld\n", ans[i]);
  return 0;
}