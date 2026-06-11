#include <iostream>

using namespace std;

#define LL long long

const int maxN = 2e3 + 2;
const int MOD = 1e9 + 7;

int N, K;
int F[maxN][maxN], fac[maxN * maxN];

LL qpow(LL a, LL b) {
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= N * K; ++i) 
        fac[i] = 1ll * fac[i - 1] * i % MOD; 
}

int Combine(int n, int m) { 
    if (n < m) return 0;
    return 1ll * fac[n] * qpow(fac[m], MOD - 2) % MOD * qpow(fac[n - m], MOD - 2) % MOD;
}

signed main() {
   
    cin >> N >> K;
    if (K == 1) return puts("1"), 0;
    init();
    F[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= i; ++j) {
            F[i][j] = (1ll * F[i - 1][j] + 1ll * (i > 0) * F[i][j - 1] *
                        Combine(N * K - (j - 1) * (K - 1) - i - 1, K - 2) % MOD) % MOD;
        }
    }
    cout << 1ll * F[N][N] * fac[N] % MOD << endl;
}
