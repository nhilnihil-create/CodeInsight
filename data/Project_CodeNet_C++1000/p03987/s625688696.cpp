#include <bits/stdc++.h>

const int MAXN = 2e5;
const int INF = 0x3f3f3f3f;

int n, a[MAXN + 9];
long long ans = 0;
int s[MAXN + 9], top = 0, l[MAXN + 9], r[MAXN + 9];

void ToLeft() {
  s[top = 1] = n;
  for (int i = n - 1; i; --i) {
    while (top && a[s[top]] > a[i]) l[s[top--]] = i + 1;
    s[++top] = i;
  }
  while (top) l[s[top--]] = 1;
}

void ToRight() {
  s[top = 1] = 1;
  for (int i = 2; i <= n; ++i) {
    while (top && a[s[top]] > a[i]) r[s[top--]] = i - 1;
    s[++top] = i;
  }
  while (top) r[s[top--]] = n;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

  ToLeft(), ToRight();
  for (int i = 1; i <= n; ++i) ans += 1LL * (i - l[i] + 1) * (r[i] - i + 1) * a[i];

  printf("%lld\n", ans);

  return 0;
}