#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int read();
int M(int x) { return x >= mod ? x - mod : x; }
int fsp(int bs, int p) {
  int rt = 1;
  while (p) {
    if (p & 1) rt = 1ll * rt * bs % mod;
    bs = 1ll * bs * bs % mod, p >>= 1;
  }
  return rt;
}

int n, k;
int fac[4000006], caf[4000006];
void init() {
  int lim = 4000000;
  fac[0] = 1;
  for (int i = 1; i <= lim; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  caf[lim] = fsp(fac[lim], mod - 2);
  for (int i = lim; i >= 1; --i) caf[i - 1] = 1ll * caf[i] * i % mod;
}
int C(int x, int y) { return 1ll * fac[x] * caf[y] % mod * caf[x - y] % mod; }
int f[2003][2003];

int main() {
  n = read(), k = read(), init();
  if (k == 1) return puts("1"), 0;
  for (int i = 1; i <= n; ++i) f[i][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      f[i][j] = M(f[i - 1][j] +
                  1ll * f[i][j - 1] * (n - j + 1) % mod *
                      C(n - i + (n - j + 1) * (k - 1) - 1, k - 2) % mod);
  printf("%d\n", f[n][n]);
  return 0;
}

int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
