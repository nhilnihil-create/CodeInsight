#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx")

#include <cstdio>
#include <algorithm>

using namespace std;

using int64 = long long;

template<class T> inline void fastin(T &num) {
  T c;
  num = 0;
  c = getchar_unlocked();
  for (; (c > 47 && c < 58); c = getchar_unlocked()) num = (num << 3) + (num << 1) + c - 48;
}

constexpr int64 INF = 1e18;

int main() {
  int n; int64 x; fastin(n); fastin(x);
  int64 a[n];
  for (int i = 0; i < n; ++i) fastin(a[i]);

  int64 dp[n][n]; fill(dp[0], dp[n], INF);

  for (int i = 0; i < n; ++i) {
    for (int move = 0; move < n; ++move) {
      int pos = (i + move) % n;
      dp[i][move] = min(dp[i][(move + n - 1) % n], a[pos]);
    }
  }

  int64 ans = INF;

  for (int move = 0; move < n; ++move) {
    int64 sum = 0;
    for (int j = 0; j < n; ++j) {
      sum += dp[j][move];
    }
    sum += move * x;
    ans = min(ans, sum);
  }

  printf("%lld\n", ans);

  return 0;
}