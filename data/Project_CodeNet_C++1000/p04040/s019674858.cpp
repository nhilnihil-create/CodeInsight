#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

long long fpow(long long a, long long b, long long m) {
    if (!b) return 1;
    long long t = fpow(a, b / 2, m);
    if (b & 1) return t * t % m * a % m;
    else return t * t % m;
}

long long f[N];
long long g[N];
int h, w, a, b;

long long fac[N];
long long inv[N];

long long comb(int n, int m) {
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

signed main() {
    cin >> h >> w >> a >> b;
    int n = w + h;
    
    fac[0] = inv[0] = 1ll;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
    inv[n] = fpow(fac[n], mod - 2, mod);
    for (int i = n - 1; i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;

    long long ans = comb(h + w - 2, h - 1);
    for (int i = 1; i <= b; i++)
        ans = (ans - comb(w - i + a - 1, a - 1)
                   * comb(h - a + i - 2, i - 1) % mod + mod) % mod;
    
    cout << ans << endl;
}