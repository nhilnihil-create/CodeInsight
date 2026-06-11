#include <bits/stdc++.h>
using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int H,W,A,B;
    cin >> H >> W >> A >> B;

    COMinit();
    long long ans = 0;
    for(int i=B; i<=W-1; ++i) {
        ans += COM(H - A - 1 + i, i) * COM(A - 1 + W - 1 - i, A - 1);
        ans %= MOD;
    }
    cout << ans << endl;
}