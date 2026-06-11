#include <cstdio>

using ll = long long;

const ll mod = 1e9+7;

ll N, M;
ll x[100001], y[100001], yy;

ll ans = 0;

int main () {
    scanf("%lld %lld", &N, &M);

    for(int n = 0; n < N; n++)
        scanf("%lld", x + n);
    for(int m = 0; m < M; m++)
        scanf("%lld", y + m);
    N--, M--;
    for(int m = 0; m < M; m++)
        (yy += (y[m+1] - y[m]) * (m+1) % mod * (M-m) % mod) %= mod;
    for(int n = 0; n < N; n++)
        (ans += (x[n+1] - x[n]) * (n+1) % mod * (N-n) % mod * yy % mod) %= mod;

    printf("%lld\n", ans);

    return 0;
}