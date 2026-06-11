#include <bits/stdc++.h>
std::vector<int> A['   '];
int n, m, S['   '], a, l, r, i, d, x;
void U(int z, int u) {
  while (z <= n)
    S[z] += u, z += z & -z;
}
int main() {
  scanf("%d%d", &m, &n);
  for (i = 1; i <= m; i++)
    scanf("%d%d", &l, &r), A[r - l + 1].push_back(l);
  for (d = 1; d <= n; d++) {
    a = m;
    for (i = d; i <= n; i += d) {
      r = 0, x = i;
      while (x)
        r += S[x], x -= x & -x;
      a += r;
    }
    for (int u : A[d])
      U(u, 1), U(u + d, -1), m--;
    printf("%d\n", a);
  }
  return 0;
}