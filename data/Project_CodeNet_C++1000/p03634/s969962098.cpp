#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

struct edge {
    ll to, cost;
};

int n;
vector<vector<edge>> g;
vector<ll> d;

//ダイクストラ法
void dijkstra(int s) {
    for (int i = 0; i < n; ++i) {
        d[i] = LINF;
    }

    //最小値を取り出す優先度付きキュー
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;

    d[s] = 0;
    que.push(make_pair(0, s)); //距離を最初にして、優先度付きキューで最小値を出せるようにする

    while (!que.empty()) {
        pair<int, int> p = que.top(); que.pop();
        int v = p.second;

        //記録してある最短距離よりも取り出した要素に入っている距離情報が大きい場合は打ち切り
        if (d[v] < p.first) continue;

        for (int i = 0; i < g[v].size(); ++i) {
            edge e = g[v][i];

            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(make_pair(d[e.to], e.to));
            }
        }
    }
}

int main() {

    cin >> n;

    g.resize(n);
    d.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;

        g[a].push_back(edge({b, c}));
        g[b].push_back(edge({a, c}));
    }

    int q, k; cin >> q >> k;
    --k;

    vector<ll> ans(q, 0);
    dijkstra(k);

    for (int i = 0; i < q; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;

        ll ans = 0;

        ans += d[x] + d[y];

        cout << ans << endl;
    }
}