#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> g(n+1);
    rep(i,m){
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(auto x:g[1]){
        for(auto y:g[x]){
            if(y == n){
                put("POSSIBLE");
                return 0;
            }
        }
    }
    put("IMPOSSIBLE");
}