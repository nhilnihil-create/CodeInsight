#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
const int MAX = 510000;
const int MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

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
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){   
    ll n,m;
    cin >> n >> m;
    COMinit();
    if(abs(n-m)==0){
        cout << (2 * ((fac[n] * fac[m]) % MOD))%MOD << endl;
    }else if(abs(n-m) == 1){
        cout << ((fac[n] * fac[m]) % MOD)%MOD << endl;
    }else{
        cout << 0 << endl;
    }
}