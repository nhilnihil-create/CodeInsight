#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

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

int main(){
    ll N,P; cin >> N >> P;
    ll o=0,e=0;
    rep(i,N){
        ll a;
        cin >> a;
        if(a%2) o++;
        else e++;
    }

    COMinit();
    unsigned long long res = 0;
    ll tmp = pow(2,e);
    if(P){     
        for(int i=1;i<=o;i+=2){
            res += tmp * COM(o,i);
        }
    }else{
        for(int i=0;i<=o;i+=2){
            res += tmp * COM(o,i);
        }
    }
    cout << res << endl;
}