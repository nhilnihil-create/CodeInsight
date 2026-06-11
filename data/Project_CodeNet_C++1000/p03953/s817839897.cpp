#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 100100

int n, x[MAX], m, d[MAX], ans[MAX], tmp[MAX];
ll K;
double a[MAX];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
  scanf("%d%lld", &m, &K);
  for (int i = 1; i <= n; ++i) d[i] = i, ans[i] = i;
  for (int i = 1, x; i <= m; ++i) scanf("%d", &x), swap(d[x], d[x + 1]);
  while (K) {
    if (K & 1) {
      for (int i = 1; i <= n; ++i) tmp[i] = ans[d[i]];
      for (int i = 1; i <= n; ++i) ans[i] = tmp[i];
    }
    for (int i = 1; i <= n; ++i) tmp[i] = d[d[i]];
    for (int i = 1; i <= n; ++i) d[i] = tmp[i];
    K >>= 1;
  }
  for (int i = 1; i <= n; ++i) a[i] = x[ans[i]] - x[ans[i] - 1];
  for (int i = 1; i <= n; ++i) printf("%.1lf\n", a[i] += a[i - 1]);
  return 0;
}
