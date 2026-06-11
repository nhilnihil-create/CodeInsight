#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

long long fac[100010], finv[100010], inv[100010];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 100010; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}


int main(){
    ll n,m;
    cin>>n>>m;

    if(abs(n-m)>=2){
        cout<<0<<endl;
        return 0;
    }
    COMinit();
    if(n+1==m || m+1==n){
        ll ans=(fac[n]*fac[m])%MOD;
        cout<<ans<<endl;
        return 0;
    }
    ll ans=(fac[n]*fac[m])%MOD;
    //cout<<ans<<endl;
    ans=(ans*2)%MOD;
    cout<<ans<<endl;
}