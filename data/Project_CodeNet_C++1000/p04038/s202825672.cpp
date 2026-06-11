#include <bits/stdc++.h>
using namespace std;
typedef long long LL; 
const int P = 1e9 + 7;
namespace Comb {
const int U = 2000 * 2000;
int f[U + 3], rf[U + 3];
LL inv(LL a, LL m) { return (a == 1 ? 1 : inv(m % a, m) * (m - m / a) % m); }
void init() {
    f[0] = 1;
    for (int i = 1; i <= U; i++) f[i] = (LL)f[i - 1] * i % P;
    rf[U] = inv(f[U], P);
    for (int i = U; i; i--) rf[i - 1] = (LL)rf[i] * i % P;
}
LL C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return (LL)f[n] * rf[m] % P * rf[n - m] % P;
}
}  // namespace Comb
using namespace Comb;
const int N = 2010;
int dp[N][N];
int main() {
	int n, k;
    init();
    scanf("%d%d", &n, &k);
    if (k == 1) {
        puts("1");
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % P;
            int lft = n * k - (i * (k - 1) + j) - 1;
            dp[i + 1][j] = (1ll * dp[i][j] * C(lft, k - 2) % P + dp[i + 1][j]) % P;
        }
    }
    printf("%lld\n", 1ll * dp[n][n] * f[n] % P);
    return 0;
}