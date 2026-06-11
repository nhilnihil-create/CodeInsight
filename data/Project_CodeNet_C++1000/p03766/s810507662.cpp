#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 1000006, MOD = 1000000007;
typedef long long i64;

void update(i64 &x, i64 y) {
  x = (x + y) % MOD;
}

i64 f[MAX_N];
int N;

int main() {
  scanf("%d", &N);
  if (N == 1) {
    puts("1");
    return 0;
  }
  
  i64 result = 0, sum = 0;
  f[0] = 1, f[1] = 1, sum = 2;
  for (int i = 2; i <= N; ++i) {
    f[i] = (sum - f[i - 2]) % MOD;
    sum = (sum + f[i]) % MOD;
  }
  
  for (int i = 1; i < N; ++i) {
    update(result, 1LL * (N - 1) * max((N - i - 2), 0) % MOD * f[i - 1] % MOD);
    update(result, 1LL * N * (i + (i < N - 1)) % MOD * f[i - 1] % MOD);
  }
  update(result, 1LL * N * f[N - 1] % MOD);
  printf("%lld\n", (result + MOD) % MOD);
  return 0;
}
