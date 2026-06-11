#include <stdio.h>
#include <queue>
typedef long long ll;

int main(void) {
  ll i, n, now = 0;
  scanf("%lld", &n);
  ll x[n], be[n * n], af[n * n], ans[n * n], cnt[n], tmp[n * n];
  for(i = 0; i < n * n; ++i) be[i] = af[i] = 0, ans[i] = tmp[i] = -1;
  for(i = 0; i < n; ++i) {
    scanf("%lld", &x[i]);
    be[--x[i]] = i + 1;
    af[x[i]] = n - i;
    ans[x[i]] = tmp[x[i]] = i;
    cnt[i] = 0;
  }
  if(be[0] > 1) {
    printf("No");
    return 0;
  }
  for(i = 1; i < n * n; ++i) {
    be[i] += be[i - 1];
    if(be[i] > i + 1) {
      printf("No");
      return 0;
    }
  }
  now = 0;
  for(i = n * n - 1; i >= 0; --i) {
    now += af[i];
    if(now > n * n - i) {
      printf("No");
      return 0;
    }
  }
  now = be[n * n - 1];
  std::queue<ll> q;
  for(i = n * n - 1; i >= 0; --i) {
    if(ans[i] != -1) {
      if(ans[i]) q.push(ans[i]);
      now--;
    }
    else if(!q.empty() && now == i + 1) {
      ans[i] = q.front();
      cnt[q.front()]++;
      if(cnt[q.front()] != q.front()) q.push(q.front());
      q.pop();
      now--;
    }
  }
  for(i = 0; i < n; ++i) cnt[i] = 0;
  for(i = 0; i < n * n; ++i) {
    if(tmp[i] != -1) {
      if(tmp[i] != n - 1) q.push(tmp[i]);
    }
    else if(ans[i] == -1) {
      ans[i] = q.front();
      cnt[q.front()]++;
      if(cnt[q.front()] != n - q.front() - 1) q.push(q.front());
      q.pop();
    }
  }
  printf("Yes\n");
  for(i = 0; i < n * n; ++i) printf("%lld ", ans[i] + 1);
  return 0;
}