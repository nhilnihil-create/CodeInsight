#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {
    ll n,m; cin >> n >> m;
    vector<ll> c(n,1),r(n,0);
    ll x,y;
    ll ans = 0;
    r[0] = 1;

    rep(i,m){
        cin >> x >> y;
        x --; y --;
        c[x] --;
        c[y] ++;

        if(r[y] > 0) r[y] ++;

        if(r[x] > 0) {
            r[x] --;
            r[y] = c[y];
        }
    }

    rep(i,n){
        if(r[i] > 0) ans ++;
    }
    cout << ans;

    return 0;
}
