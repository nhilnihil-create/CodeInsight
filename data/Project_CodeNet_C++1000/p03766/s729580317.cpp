#include <cstdio>
#include <cmath>
#include <algorithm>
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);
using namespace std;
const int MAXN = 1000005;
const int MOD = 1e9 + 7;
int n;
int f[MAXN], sum[MAXN], ans;

int main() {
    scanf("%d", &n);
    int n_1_2 = 1ll * (n - 1) * (n - 1) % MOD;
    f[0] = sum[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = i >= 3 ? sum[i - 3] : 0;
        sum[i] = sum[i - 1];
        f[i] = (f[i] + f[i - 1]) % MOD, sum[i] = (sum[i] + f[i]) % MOD;
    }
    for (int i = 0; i < n - 1; i++)
        ans = (ans + 1ll * f[i] * n_1_2) % MOD;
    for (int i = 0; i < n - 1; i++)
        ans = (ans + 1ll * f[i] * (i + 1)) % MOD;
    ans = (ans + 1ll * f[n - 1] * (n - 1) + f[n]) % MOD;
    printf("%d", ans);
	return 0;
}
