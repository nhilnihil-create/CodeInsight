#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
ll modfact(ll x,ll mod){
    ll res = 1;
    for (ll i = 1; i <= x;i++){
        (res *= i) %= mod;
    }
    return res;
}
int main() {
ll n,m;
cin >> n >> m;
ll ans = 1;
if(abs(n-m)>1){
    cout << "0" << endl;
    return 0;
}
if(n!=m){
    ans *= modfact(n, MOD);
    ans %= MOD;
    ans *= modfact(m, MOD);
    ans %= MOD;
}
else{
    ans *= modfact(n, MOD);
    ans %= MOD;
    ans *= modfact(m, MOD);
    ans %= MOD;
    ans *= 2;
    ans %= MOD;
}
cout << ans << endl;
}
