#include <bits/stdc++.h>
#define L(x) ((x) & -(x))
std::vector<int> e['   '];
int n, m, s['   '], a;
void U(int x, int u) {
  while (x <= n)
    s[x] += u, x += L(x);
}
int Q(int x) {
  int r = 0;
  while (x)
    r += s[x], x -= L(x);
  return r;
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1, l, r; i <= m; i++)
    scanf("%d%d", &l, &r), e[r - l + 1].push_back(l);
  for (int d = 1; d <= n; d++) {
    a = m;
    for (int i = d; i <= n; i += d)
      a += Q(i);
    for (int u : e[d])
      U(u, 1), U(u + d, -1), m--;
    printf("%d\n", a);
  }
  return 0;
}