#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];
long long pre[N], suf[N], sum[N];

int main() {
  int n, k;
  long long ans = 0;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + max(a[i], 0);
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + max(a[i], 0);
  for (int i = 0; i <= n - k; i++)
    ans = max(ans, pre[i] + suf[i + k + 1] + max(sum[i + k] - sum[i], 0LL));
  printf("%lld\n", ans);
  return 0;
}
