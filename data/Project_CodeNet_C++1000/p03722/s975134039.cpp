#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)b; i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const ll INF = 1e18;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

struct edge {
    int from, to, cost;
};

bool reachableFrom1[1005];
bool reachableToN[1005];
vector<int> g[1005];
vector<int> rg[1005];

void dfs(int v) {
    if (reachableFrom1[v]) return;
    reachableFrom1[v] = true;
    for (int nv : g[v]) {
        dfs(nv);
    }
}

void rdfs(int v) {
    if (reachableToN[v]) return;
    reachableToN[v] = true;
    for (int nv : rg[v]) {
        rdfs(nv);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c *= -1;
        edge tmp = {a, b, c};
        edges.push_back(tmp);
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    dfs(0);
    rdfs(n - 1);

    vector<ll> dist(n, INF);
    dist[0] = 0;
    rep(i, 0, n) {
        for (auto e : edges) {
            if (!reachableFrom1[e.from] || !reachableToN[e.from]) continue;
            if (!reachableFrom1[e.to] || !reachableToN[e.to]) continue;
            if (dist[e.from] == INF) continue;
            if (dist[e.to] > dist[e.from] + e.cost) {
                if (i == n - 1) {
                    cout << "inf" << endl;
                    return 0;
                }
                dist[e.to] = dist[e.from] + e.cost;
            }
        }
    }
    cout << -dist[n - 1] << endl;
    return 0;
}
