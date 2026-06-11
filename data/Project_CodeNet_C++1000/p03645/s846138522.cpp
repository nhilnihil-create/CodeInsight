#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

vector<bool> visited;
bool can = false;
bool dfs(const vector<vector<ll>> &g, ll v, ll goal){
    visited[v] = true;
    
    for(auto next_v: g[v]){
        if(next_v == goal) can = true;
        if(visited[next_v]) continue;
        dfs(g, next_v, goal);
    }
}

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n+1, vector<ll>());
    rep(i, m){
        ll aa, b;
        cin >> aa >> b;
        if(aa == 1) a[aa].push_back(b);
        else{
            if(b == n){
                a[aa].push_back(b);
                a[b].push_back(aa);
            }
        }
    }
    //visited.assign(n+1, false);
    //dfs(a, 1, n);
    rep(i, a[1].size()){
        rep(j, a[a[1][i]].size()){
            if(a[a[1][i]][j] == n){
                can = true;
                break;
            }
        }
    }
    if(can) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}