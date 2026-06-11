#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll lcm(ll x, ll y) {
    return x / GCD(x, y) * y;//先に割り算をして掛けられる数を小さくして掛け算を行う
}
const int MAX = 510000;
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
    ll mod = 1000000007;
    int N, M;
    cin >> N >> M;
    ll ans1 = 1;
    ll ans2 = 1;
    if (abs(N - M) > 1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i = 1; i <= N; i++)
    {
      ans1 *= i;
      ans1 %= mod;
    }
    

    for (int i = 1; i <= M; i++)
    {
        ans2 *= i;
        ans2 %= mod;
    }
    //cout << ans2 << endl;
    ll ans = ans1;
    ans *= ans2;
    ans %= mod;
    if (N == M) {
    ans *= 2;
    ans %= mod;
    }
    cout << ans << endl;
    
    
    
    

    return 0;

}
