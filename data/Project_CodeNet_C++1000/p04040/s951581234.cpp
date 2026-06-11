#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int N = 200005;
int fac[N] = {1, 1}, rfac[N] = {1, 1}, inv[N] = {0, 1};
const int mod = 1e9 + 7;
int nCr(int n, int r) {return 1ll * fac[n] * rfac[n-r] % mod * rfac[r] % mod;}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 2; i < N; i ++) {
        inv[i] = 1ll * (mod / i) * (mod - inv[mod%i]) % mod;
        fac[i] = 1ll * fac[i-1] * i % mod;
        rfac[i] = 1ll * rfac[i-1] * inv[i] % mod;
    }

    LL n, m, a, b;
    cin >> n >> m >> a >> b;

    LL ans = nCr(n + m - 2, m - 1);
    for(LL i = n-a+1; i <= n; i++) {
        LL x = nCr(i-1 + b-1, b-1), y = nCr(n-i + m-b-1, n-i);
        LL z = (x * y) % mod;
        ans -= z;
        if(ans < 0) ans += mod;
    }
    cout << ans;
}
