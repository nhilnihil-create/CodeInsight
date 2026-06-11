#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 2020;
const int MAX = MAXN * MAXN;
const int mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }

inline int sub(int a, int b) { return a >= b ? a - b : a - b + mod; }

inline int mul(int a, int b) { return llint(a) * b % mod; }

int f[MAXN][MAXN];

int fact[MAX];
int inv[MAX];
int invfact[MAX];

int choose(int n, int k) {
  return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int main(void) {
  inv[1] = 1;
  FOR(i, 2, MAX) inv[i] = sub(0, mul(mod / i, inv[mod % i]));

  fact[0] = invfact[0] = 1;
  FOR(i, 1, MAX) {
    fact[i] = mul(fact[i - 1], i);
    invfact[i] = mul(invfact[i - 1], inv[i]);
  }

  int N, K;
  scanf("%d %d", &N, &K);

  if (K == 1) {
    printf("%d\n", 1);
    return 0;
  }

  f[0][0] = 1;
  REP(i, N + 1) REP(j, N + 1) {
    if (j < i) continue;

    if (j + 1 <= N) {
      f[i][j + 1] = add(f[i][j + 1], f[i][j]);
    }

    if (i + 1 <= j) {
      int rem_spots = N * K - i * (K - 1) - j - 1;
      int need_spots = K - 2;

      int ways = choose(rem_spots, need_spots);
      ways = mul(ways, N - i);
      f[i + 1][j] = add(f[i + 1][j], mul(ways, f[i][j]));
    }
  }

  printf("%d\n", f[N][N]);
  return 0;
}
