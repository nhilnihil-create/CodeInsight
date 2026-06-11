#include <iostream>

using namespace std;

constexpr int64_t MOD = 1'000'000'007;
constexpr int     MAX =       200'005;

int64_t fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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

// 二項係数計算
int64_t COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void) {
    int64_t H, W, A, B;
    cin >> H >> W >> A >> B;
    COMinit();

    int64_t ans = 0;
    for(int i=0; i<H-A; i++) {
        ans += COM(B-1+i, i) * COM(H-i+W-B-2, W-B-1);
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
