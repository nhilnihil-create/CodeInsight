#include<bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
const int Mod = 1e9 + 7;

int add(int a, int b) {
  return (a += b) >= Mod ? a - Mod : a;
}

int sub(int a, int b) {
  return (a -= b) < 0 ? a + Mod : a;
}

int mul(int a, int b) {
  return 1ll * a * b % Mod;
}

int fast_pow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) {
      res = mul(res, a);
    }
  }
  return res;
}

int n, k, f[N][N], inv[N * N], fac[N * N];

void init(int limit) {
  inv[0] = fac[0] = 1;
  for (int i = 1; i <= limit; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
  inv[limit] = fast_pow(fac[limit], Mod - 2);
  for (int i = limit - 1; i >= 1; i--) {
    inv[i] = mul(inv[i + 1], i + 1);
  }
}

int C(int a, int b) {
  return (a >= b) ? mul(fac[a], mul(inv[b], inv[a - b])) : 0;
}

int main() {
  scanf("%d %d", &n, &k);
  if (k == 1) {
    puts("1");
    return 0;
  }
  init(n * k);
  f[0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (i) {
        f[i][j] = f[i - 1][j];
      }
      if (j > i) {
        f[i][j] = add(f[i][j], mul(f[i][j - 1], C(i + j * (k - 1) - 1, k - 2)));
      }
    }
  }
  printf("%d\n", mul(f[n][n], fac[n]));
  return 0;
}