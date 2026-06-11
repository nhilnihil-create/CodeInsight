#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7, N = 1e5 + 10;
ll h, w, a, b;
ll fac[N << 1], inv[N << 1];

ll quick_pow(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    } return res;
}

ll C(ll n, ll m) {
    return (fac[n] * inv[m] % mod) * inv[n - m] % mod;
}

int main() {
    cin >> h >> w >> a >> b;

    fac[0] = inv[0] = 1;
    for (int i = 1; i <= h + w; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = quick_pow(fac[i], mod - 2);
        // printf("%lld %lld\n", fac[i], inv[i]);
    }
    ll tot = C(h + w - 2, h - 1);
    ll minus = 0;
    for (int i = 1; i <= b; i++)
        minus = (minus + C(h - a + i - 2, i - 1) * C(w + a - 1 - i, a - 1) % mod) % mod;
    printf("%lld\n", ((tot - minus) % mod + mod) % mod);
    return 0;
}
