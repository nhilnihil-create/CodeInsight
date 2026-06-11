#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, Q, K;
vector<pll> adj[100010];
ll dist[100010];

void dfs(ll i, ll d){
    if(dist[i] != -1) return;
    dist[i] = d;
    for(pll p : adj[i]){
        dfs(p.first, d + p.second);
    }
}

signed main(){
    cin >> N;
    ll a, b, c;
    REP(i, N - 1){
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> Q >> K;
    K--;
    REP(i, N) dist[i] = -1;
    dfs(K, 0);
    REP(i, Q){
        cin >> a >> b;
        a--; b--;
        PRINT(dist[a] + dist[b]);
    }
    return 0;
}