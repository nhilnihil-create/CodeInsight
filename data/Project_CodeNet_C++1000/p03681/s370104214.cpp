#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

ll f(ll x){
    ll ret  = 1;
    for(ll i = x; i > 1; i--){
        ret *= i;
        ret = ret % ll(1e9+7);
    }
    return ret;
}

int main(){
    ll n, m; cin >> n >> m;
    if(n == m){
        put((f(n) * f(m)) * 2 % ll(1e9+7));
    }else if(abs(n - m) == 1){
        put((f(n) * f(m)) % ll(1e9+7));
    }else{
        put(0);
    }
}