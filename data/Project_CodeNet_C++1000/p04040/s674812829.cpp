#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int maxn = 3e5 + 5;
long long fact_my[maxn], inv_my[maxn];
long long pow_mod(long long b, int p) {
    long long res = 1;
    long long pow = b;
    while (p > 0) {
        if ((p & 1) != 0) res *= pow, res %= MOD;
        pow = pow * pow;
        pow %= MOD;
        p >>= 1;
    }

    return res;
}
long long C(int n, int k) {
    return (((fact_my[n] * inv_my[k]) % MOD) * inv_my[n - k]) % MOD;

}

int main() {
    int H, W, A, B;
    fact_my[0] = inv_my[0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        fact_my[i] = (fact_my[i - 1] * i) % MOD;
        inv_my[i] = (pow_mod(fact_my[i], MOD - 2)) % MOD;
    }
    scanf("%d%d%d%d", &H, &W, &A, &B);
    H--, W--, A--, B--;
    long long res = 0;
    for (int i = 0; i < W - B; ++i) {
        res += ((C(H - A + B + 1 + i, B + 1 + i) - C(H - A + B + i, B + i) + 3LL * MOD) % MOD) * C(A + W - B - i - 1, A);
        res %= MOD;

    }
    printf("%lld\n", res);
    return 0;
}
