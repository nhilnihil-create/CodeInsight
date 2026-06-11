#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 1e6 + 9;
vector<ll>adj[mx];
bitset<mx>mark;
ll dist[mx];

int main() {
    ll n, m; cin >> n >> m;
    for(ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool nafisa = false;
    ll source = 1;
    mark[source] = 1;
    queue<ll>q;
    q.push(source);
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        if(u == n && dist[u] == 2) {
            nafisa = true;
            break;
        }
        for(auto v : adj[u]) {
            if(!mark[v]) {
            mark[v] = 1;
            dist[v] = dist[u] + 1;
            q.push(v);
            }
        }
    }
    if(nafisa) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;

}