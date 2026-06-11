#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int mod = (int)1e9 + 7;
const int N = (int)3e5 + 7;

int mul(int a, int b) {
  return (a * 1LL * b) % mod;
}

int add(int a, int b) {
  return (a + b) % mod;
}

int h, w, a, b;
int fact[N], rfact[N];

int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1)
      res = mul(res, a);
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}

void precalc() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  rfact[N - 1] = binpow(fact[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) {
    rfact[i] = mul(rfact[i + 1], i + 1);
  }
}

int cnk(int n, int k) {
  return mul(fact[n], mul(rfact[n - k], rfact[k]));
}

int get(int n, int m) {
  return cnk(n + m - 2, n - 1);
}

main() {
  precalc();
  scanf("%d %d %d %d", &h, &w, &a, &b);
  int ans = 0;
  for (int i = b + 1; i <= w; i++) {
    ans = add(ans, mul(get(h - a, i), get(a, w - i + 1)));
  }
  cout << ans;
}
