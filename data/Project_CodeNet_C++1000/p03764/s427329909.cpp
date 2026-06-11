#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
const ll MOD = 1e9 + 7;
int main(){
    ll n, m;
    cin >> n >> m;
    ll po = 0, yo = 0;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        x *= (2 * i - n + 1);
        po += x;
        if(po < 0) po += -po / MOD * MOD + (-po % MOD ? MOD : 0);
        po %= MOD;
    }
    for(ll i = 0; i < m; i++){
        ll y;
        cin >> y;
        y *= (2 * i - m + 1);
        yo += y;
        if(yo < 0) yo += -yo / MOD * MOD + (-yo % MOD ? MOD : 0);
        yo %= MOD;
    }
    cout << po * yo % MOD << endl;
    return 0;
}