#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int kMaxN = 5005, kMod = 1e9 + 7;
int n, len;
ll f[kMaxN][kMaxN];
char str[kMaxN];

ll QuickPow(ll x, ll y) {
  ll ret = 1;
  for (; y; y >>= 1, x = x * x % kMod)
    if (y & 1) ret = ret * x % kMod;
  return ret;
}

int main() {
  scanf("%d\n%s", &n, str + 1);
  len = strlen(str + 1);
  f[0][0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= i; ++j) {
      f[i + 1][j + 1] = (f[i + 1][j + 1] + 2LL * f[i][j] % kMod) % kMod;
      f[i + 1][max(j - 1, 0)] = (f[i + 1][max(j - 1, 0)] + f[i][j]) % kMod;
    }
  printf("%lld\n", f[n][len] * QuickPow(QuickPow(2, len), kMod - 2) % kMod);
  return 0;
}