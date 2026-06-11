#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;
const ll mod = 1e9 + 7;

ll f(ll x){
    ll k = 1;
    while(x != 1){
        k = k*x%mod;
        x--;
    }
    return k;
}

int main(){
    ll n,m;
    cin >> n >> m;
    ll t = abs(n-m);
    if(t > 1) cout << 0 << endl;
    else {
        ll a = f(n);
        ll b = f(m);
        ll ans = a*b%mod;
        if(t == 0)cout << ans*2%mod << endl;
        else cout << ans << endl;
    }
}