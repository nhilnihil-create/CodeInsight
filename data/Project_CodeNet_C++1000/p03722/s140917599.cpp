#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (ll i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<ll, ll>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const ll INF = 1E+18;

struct Edge {
    ll u, v, c;
    Edge(ll u, ll v, ll c): u(u), v(v), c(c) {}
};

vector<ll> to[1005];
vector<ll> rto[1005];

bool reachable1[1005];
bool reachable2[1005];
bool ok[1005];
void dfs(ll v, ll p=-1) {
    reachable1[v] = true;
    for (ll e: to[v]) {
        if (e==p) continue;
        if (!reachable1[e]) dfs(e, v);
    }
}
void dfs2(ll v, ll p=-1) {
    reachable2[v] = true;
    for (ll e: rto[v]) {
        if (e==p) continue;
        if (!reachable2[e]) dfs2(e, v);
    }
}


int main(){
    ll n, m;
    cin >> n >> m;
    vector<Edge> edge;
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        c *= -1;
        edge.emplace_back(a, b, c);
        to[a].push_back(b);
        rto[b].push_back(a);
    }
    dfs(0);
    dfs2(n-1);
    rep(i, n) {
        ok[i] = reachable1[i] && reachable2[i];
    }
    vector<ll> dist(n);
    rep(i, n) dist[i] = INF;
    dist[0] = 0;
    bool update = false;
    rep(i, n) {
        update = false;
        for (auto e: edge) {
            ll u = e.u;
            ll v = e.v;
            ll c = e.c;
            if (!ok[u]) continue;
            if (!ok[v]) continue;
            if (dist[v]>dist[u]+c) {
                update = true;
                dist[v] = dist[u] + c;
            }
        }
        if (!update) break;
    }
    if (update) {
        cout << "inf" << endl;
        return 0;
    }

    ll ans = -dist[n-1];
    
    cout << ans << endl;
    return 0;
}
