#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
const int MAX = 510000;
//const int MOD = 998244353;
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

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    // 前処理
    COMinit();
    int N,P;
    cin >> N >> P;
    vector<int> A(N);
    ll odd=0,even=0;
    rep(i,N){
        cin >> A[i];
        if(A[i]%2==0) even++;
        else odd++;
    }
    ll ans = 0;
    ll tmp = 0;
    ans += (ll)powl(2,even);
    if(P==1){
        for(int i=1;i<=odd;i+=2){
            tmp += COM(odd,i);
        }
    }else{
        for(int i=0;i<=odd;i+=2){
            tmp += COM(odd,i);
        }
    }
    ans *= tmp;
    cout << ans << endl;
    return 0;
}