#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

const int MAX = 510000;
// const int MOD = 1000000007;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int N, P;
    cin >> N >> P;

    int a, ne = 0, no = 0;
    rep(i, N) {
        cin >> a;
        if (a%2==0) ne++;
        else no++;
    }

    COMinit();

    ll ans = 0;
    if (P==0) {
        for (int k=0; k<=no; k+=2) ans += COM(no, k);
    } else {
        for (int k=1; k<=no; k+=2) ans += COM(no, k);
    }

    rep(k, ne) ans *= 2;
    cout << ans << endl;

    return 0;
}