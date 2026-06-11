#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

ll keta(ll x){
    ll res = 0;
    while(x > 0){
        x/=10;
        res++;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll ans = keta(n);
    for(ll i = 1; i*i <= n; ++i){
        if(n%i!=0) continue;
        ll t = n/i;
        ll k = max(keta(t), keta(i));
        ans = min(ans, k);
    }
    cout << ans << endl;
    return 0;
}