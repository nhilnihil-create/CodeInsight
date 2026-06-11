#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }


struct Edge {
    ll to;
    ll weight;
    Edge(ll t, ll w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, ll>;


typedef vector<vector<int> > Matrix;

const int INF = 100000000;
Matrix d;

void warshall_floyd(int n) { // nは頂点数
    for (int i = 0; i < n; i++)      // 経由する頂点
        for (int j = 0; j < n; j++)    // 開始頂点
            for (int k = 0; k < n; k++)  // 終端
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main() {
    int n,m; cin >> n >> m;
    Graph G(n);
    vector<vector<int>> keiro(n, vector<int>(n, -1));

    d = Matrix(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) d[i][i] = 0;
    rep(i, m) {
        int a,b,c; cin >> a >> b >> c;
        a--;
        b--;
        G[a].emplace_back(b,c);
        G[b].emplace_back(a,c);
        d[a][b] = c;
        d[b][a] = c;
        keiro[a][b] = i;
        keiro[b][a] = i;
    }

    warshall_floyd(n);

    vector<bool> use(m, false);
    rep(i, n) for(Edge e : G[i]) {
        int u = e.to;
        if(d[i][u] == e.weight) use[keiro[i][u]] = true;
    }

    int ans = 0;
    rep(i, m) if(!use[i]) ans++;

    cout << ans << endl;

    return 0;
}

