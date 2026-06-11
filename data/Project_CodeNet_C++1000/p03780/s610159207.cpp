#pragma GCC optimize("unroll-loops")

#include <cstdio>
#include <vector>

using namespace std;

using int64 = long long;

bool dp1[5050][5050];
bool dp2[5050][5050];

template<class T> inline void fastin(T &num) {
  T c;
  num = 0;
  c = getchar_unlocked();
  for (; (c > 47 && c < 58); c = getchar_unlocked()) num = (num << 3) + (num << 1) + c - 48;
}

int main() {
  int n, k; fastin(n); fastin(k);
  int a[n];
  for (int i = 0; i < n; ++i) fastin(a[i]);

  dp1[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (dp1[i][j]) dp1[i + 1][j] = 1;
      if (j + a[i] > 5000) continue;
      dp1[i + 1][j + a[i]] |= dp1[i][j];
    }
  }

  dp2[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if(dp2[i][j]) dp2[i + 1][j] = 1;
      if (j + a[n - 1 - i] > 5000) continue;
      dp2[i + 1][j + a[n - 1 - i]] |= dp2[i][j];
    }
  }

  int need = 0;

  for (int i = 1; i <= n; ++i) {
    int target = max(0, k - a[i - 1]);
    for (int j = target; j <= k - 1; ++j) {
      for (int l = 0; l <= j; ++l) {
        if (dp1[i - 1][l] && dp2[n - i][j - l]) {
          ++need;
          j = l = k + 5;
        }
      }
    }
  }

  printf("%d\n", n - need);

  return 0;
}