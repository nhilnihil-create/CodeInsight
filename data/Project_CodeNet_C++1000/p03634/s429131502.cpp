#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

typedef struct edge_ {
    int to;
    ll cost;
} edge;

vector<ll> dist;
vector<vector<edge> > G;


void dfs(int s) {
    for (auto e: G[s]) {
        int u = e.to;   ll d = e.cost;
        if (dist[u] >= 0)
            continue;
        
        dist[u] = dist[s] + d;
        dfs(u);
    }
}

int main() {
    int n;  cin >> n;
    G.resize(n);
    vector<ll> ans;
    for (int i = 0; i < n-1; i++) {
        int a, b;   ll c;   cin >> a >> b >> c;
        edge e1 = {b-1, c}, e2 = {a-1, c};
        G[a-1].push_back(e1);
        G[b-1].push_back(e2);
    }

    int q, k;   cin >> q >> k;
    ans.resize(q);
    dist.resize(n, -1);
    dist[k-1] = 0;
    dfs(k-1);
    for (int i = 0; i < q; i++) {
        int x, y;   cin >> x >> y;
        ans[i] = dist[x-1] + dist[y-1];
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;
    return 0;
}