#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;
const ll mod = 1e9 + 7;

ll f(ll n){
    ll res = 1;
    for(int i = n;i > 0;i--){
        res *= i;
        res %= mod;
    }
    return res;
}

int main(){
    ll n,m;
    cin >> n >> m;
    ll ok = abs(n-m);
    if(ok > 1)cout << 0 << endl;
    else{
        ll a = f(n);
        ll b = f(m);
        ll ans = a*b%mod;
        if(ok < 1) ans *= 2;
      	ans %= mod;
        cout << ans << endl;
    }
}