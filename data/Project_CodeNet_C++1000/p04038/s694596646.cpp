#include <iostream>

using namespace std;
const int N = 2e3 + 5;
const int mod = 1e9 + 7;
typedef long long LL;

LL fastpow(LL a, LL b) {
    if (!b) return 1;
    LL t = fastpow(a, b / 2);
    if (b & 1) return t * t % mod * a % mod;
    else return t * t % mod;
}

LL fact[N * N], invf[N * N];
void prework(int n) {
    fact[0] = 1ll;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
    invf[n] = fastpow(fact[n], mod - 2ll);
    for (int i = n - 1; ~i; i--)
        invf[i] = invf[i + 1] * (i + 1) % mod;
}

LL comb(int n, int m) {
    return fact[n]
         * invf[m] % mod
         * invf[n - m] % mod;
}

int k, n;
LL f[N][N];

signed main() {
    prework(4e6);
    cin >> n >> k;

    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i <= n; i++)
        f[i][0] = 1ll;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            f[i][j] += (f[i][j - 1] * (n - j + 1) % mod
                     * comb(n - i + (n - j + 1) * (k - 1) - 1, k - 2) % mod
                     + f[i - 1][j]) % mod;
        }
    
    cout << f[n][n] << endl;
    return 0;
}//233