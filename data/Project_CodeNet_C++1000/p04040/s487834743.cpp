#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
ll fact[200010];
ll powmod(ll x,ll n){
    if(n == 0)return 1;
    ll ans = powmod(x*x%MOD,n/2);
    if(n % 2)ans = ans * x % MOD;
    return ans;
}
ll divmod(ll a,ll b){
    return ((a%MOD) * (powmod(b,MOD-2)%MOD)) % MOD;
}
ll combi(ll n,ll r){
    /*
    ll num = 1;
    for(ll i = 1;i <= r;i++){
        num = divmod((n-i+1)*num,i);
    }
    */
    return divmod(fact[n], (fact[n-r] * fact[r]) % MOD);
}
main(){
    fact[0] = 1;
    rep(i,1,200010)fact[i] = (fact[i-1] * i) % MOD;
    ll H,W,A,B;
    cin >> H >> W >> A >> B;
    ll ans = 0;
    rep(i,1,H-A+1){
        ll x1 = 1, x2 = B, x3 = W;
        ll y1 = 1, y2 = i, y3 = H;
        ans += (combi(x2 - x1 + y2 - y1, y2 - y1) * combi(x3 - x2 + y3 - y2 - 1, y3 - y2)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}