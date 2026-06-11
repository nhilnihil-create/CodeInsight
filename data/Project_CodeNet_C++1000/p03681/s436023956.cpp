#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

ll factorual(ll n){
    ll res = 1;
    for (ll i = 1; i <= n; i++){
        res *= i;
        res %= MOD;
    }
    return res;

    //階乗を出力
    //入力:ll
    //出力:ll
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;

    if (abs(n-m) > 1){
        cout << 0 << endl;
        return 0;
    }

    if (n == m){
        ll x = factorual(n);
        ll ans = (2*x*x)%MOD;
        cout << ans << endl;
    }
    else{
        ll ans = (factorual(n) * factorual(m))%MOD;
        cout << ans << endl;
    }
}