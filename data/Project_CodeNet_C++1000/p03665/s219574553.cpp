#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long
const int MAX = 510000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

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
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(){
    int n,p; cin >> n >> p;
    ll all = pow(2,n);
    COMinit();
    vector<int> a(n);
    map<int,int> mp;
    rep(i,n){
        int a; cin >> a;
        mp[a%2]++;
    }
    if(mp[1]==0) cout << (p==0?(1LL<<n):0) << endl;
    else cout << (1LL<<(n-1)) <<endl;
}