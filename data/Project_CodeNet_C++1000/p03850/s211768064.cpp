#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long i64;
const int MAX_N = 100005;

i64 f[MAX_N][3];

inline void update(i64 &x, i64 y) {
  if (x < y) x = y;
}

int main() {
  int N, A;
  scanf("%d", &N);
  memset(f, -0x3f, sizeof f);

  scanf("%d", &A), f[0][0] = A;
  
  for (int i = 1; i < N; ++i) {
    static char op[10];
    scanf("%s", op);
    scanf("%d", &A);
    for (int j = 0; j < 3; ++j) {
      int val = (j & 1) ? 1 : 0, w;
      if (*op == '-') val ^= 1;
      w = A * (val & 1 ? -1 : 1);
      if (*op == '-' && j < 2) update(f[i][j + 1], f[i - 1][j] + w);
      if (j > 0) update(f[i][j - 1], f[i - 1][j] + w);
      update(f[i][j], f[i - 1][j] + w);
    }
  }

  printf("%lld\n", f[N - 1][0]);
  return 0;
}
