// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
  
inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int N = 4000005;
const int mod = 1e9 + 7;

int fac[N], inv[N];
int qpow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
void pre(int n) {
  fac[0] = inv[0] = 1;
  for (rint i = 1; i <= n; i++) {
    fac[i] = 1ll * fac[i - 1] * i % mod; 
  }
  inv[n] = qpow(fac[n], mod - 2);
  for (rint i = n - 1; i >= 1; i--) {
    inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  }
}
int C(int n, int m) {
  return 1ll * fac[n] * inv[n - m] % mod * inv[m] % mod; 
}
int f[2002][2002], n, k;
int main() {
  scanf("%d%d", &n, &k);
  if (k == 1) {
    puts("1");
    exit(0);
  }
  pre(n * k);
  for (rint i = 1; i <= n; i++) {
    f[i][0] = 1;
  }
  for (rint i = 1; i <= n; i++) {
    for (rint j = 1; j <= i; j++) {
      f[i][j] = (f[i - 1][j] + 1ll * f[i][j - 1] * (n - j + 1) % mod * C(n * k - i - (j - 1) * (k - 1) - 1, k - 2) % mod) % mod;
    }
  }
  printf("%d\n", f[n][n]);
  return 0; 
}