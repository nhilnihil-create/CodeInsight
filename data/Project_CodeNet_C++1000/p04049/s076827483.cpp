#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;

const ll INF = 5e15;
vector<vector<ll>> edges;
ll N, K;

P dfs(ll now, ll pre, ll depth, ll bound1, ll bound2){
    P ret(0, 0);
    for(ll nxt : edges[now]){
        if(nxt == pre) continue;
        P tmp = dfs(nxt, now, depth + 1, bound1, bound2);
        ret.first += tmp.first;
        ret.second += tmp.second;
    }
    if(depth > bound1) ret.first++;
    if(depth > bound2) ret.second++;
    return ret;
}

ll calc(ll parent){
    vector<P> costs;
    for(ll nxt : edges[parent]) costs.push_back(dfs(nxt, parent, 1, K / 2, (K + 1) / 2));
    sort(costs.begin(), costs.end(), [](const P &a, const P &b){ return a.first - a.second > b.first - b.second; });
    ll ret = 0;
    ret += costs[0].second;
    for(ll i = 1; i < costs.size(); i++) ret += costs[i].first;
    return ret;
}

int main(){
    cin >> N >> K;
    edges.resize(N);
    for(ll i = 1; i < N; i++){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    ll ans = INF;
    for(ll i = 0; i < N; i++) ans = min(ans, calc(i));
    cout << ans << endl;
    return 0;
}
