#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;
const int N = 5555;

char s[N];
int dp[N][N];

inline void add(int& a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline void sub(int& a, int b) {
  a -= b;
  if (a < 0) {
    a += md;
  }
}

inline int mul(int a, int b) {
  return a * 1LL * b % md;
}

inline int power(int a, int b) {
  int ret = 1;
  while (b > 0) {
    if (b & 1) {
      ret = mul(ret, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return ret;
}

inline int inv(int a) {
  return power(a, md - 2);
}

int main() {
  int n;
  scanf("%d %s", &n, s);
  int m = strlen(s);
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] = (j == 0 ? dp[i - 1][j] : mul(dp[i - 1][j - 1], 2));
      add(dp[i][j], dp[i - 1][j + 1]);
    }
  }
  int ans = mul(dp[n][m], inv(power(2, m)));
  printf("%d\n", ans);
  return 0;
}