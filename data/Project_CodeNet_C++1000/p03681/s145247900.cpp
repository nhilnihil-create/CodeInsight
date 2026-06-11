#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = pow(10, 9) + 7;

int main(){
    ll n, m;
    cin >> n >> m;
    if(max(n,m) - min(n,m) > 1) cout << 0 << endl;
    else{
        ll x = min(n, m);
        ll ans = 1;
        for(ll i = 1; i <= x; i++){
            ans *= (i * i) % mod;
            ans %= mod;
        }
        if(n == m) ans *= 2%mod;
        else ans *= (x + 1)%mod;
        cout << ans%mod << endl;
    }
}