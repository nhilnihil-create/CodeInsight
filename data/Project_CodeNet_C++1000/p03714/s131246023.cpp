#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;
const long long MOD = 1000000007;

typedef long long ll;

int
main(int argc, const char *argv[])
{
  int n; ll a[300010];
  scanf("%d", &n);
  for (int i = 0; i < 3 * n; i++) scanf("%lld", &a[i]);

  ll sum = 0;
  
  priority_queue<ll> que;
  for (int i = 0; i < n; i++) {
    que.push(-a[i]);
    sum += a[i];
  }

  ll sumf[300010]; ll Min;
  sumf[n - 1] = sum;
  for (int i = n; i < 2 * n; i++) {
    que.push(-a[i]);
    Min = -(que.top());
    que.pop();
    sumf[i] = sumf[i - 1] - Min + a[i];
  }

  sum = 0;

  priority_queue<ll> euq;
  for (int i = 3 * n - 1; i >= 2 * n; i--) {
    euq.push(a[i]);
    sum += a[i];
  }

  ll sumb[300010]; ll Max;
  sumb[2 * n] = sum;
  for (int i = 2 * n - 1; i >= n; i--) {
    euq.push(a[i]);
    Max = euq.top();
    euq.pop();
    sumb[i] = sumb[i + 1] - Max + a[i];
  }

  ll ans = -100000000000000;
  for (int i = n - 1; i < 2 * n; i++) {
    ans = max(ans, sumf[i] - sumb[i + 1]);
  }
  
  printf("%lld\n", ans);

  return 0;
}
