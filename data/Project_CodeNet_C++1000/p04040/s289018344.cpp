#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

const int MAX = 200005;

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

int main(){
    COMinit();
    int H,W,A,B; cin>>H>>W>>A>>B;

    ll ans=0ll;

    for (int i = B+1; i <=W ; ++i) {
        (ans+=COM(H-A-1+i-1,i-1)*COM(A-1+W-i,A-1)%MOD)%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}