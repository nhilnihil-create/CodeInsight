#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

vector<vector<pair<ll,ll>>> to(200000);
vector<ll> dis(200000);

void dfs(ll a,ll c,ll p = -1){
    dis[a] = c;
    for(auto r:to[a]){
        if(r.first == p) continue;
        dfs(r.first,c+r.second,a);
    }
}

int main(){
    ll n;
    cin >> n;
    for(ll i = 0; i < n-1; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        to[a].push_back({b,c});
        to[b].push_back({a,c});
    }
    ll q,k;
    cin >> q >> k;
    k--;
    dfs(k,0);
    vector<ll> ans(q);
    for(ll i = 0; i < q; i++){
        ll x,y;
        cin >> x >> y;
        x--;y--;
        ans[i] = dis[x]+dis[y];
    }
    for(ll i = 0; i < q; i++) cout << ans[i] << endl;
    return 0;
}