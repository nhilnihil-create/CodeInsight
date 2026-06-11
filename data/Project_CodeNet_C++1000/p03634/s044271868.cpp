#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

// 頂点の持つ情報
struct edge {
    ll to;
    ll cost;
};

//最短距離と、頂点の番号
using P = pair<ll, ll>;

int N;
int inf = 1e9;
// グラフと距離
vector<vector<edge>> G(10);
vector<ll> d(10);

void dijkstra(int s) {
    // Pの最初の値（距離）が小さい順で並べるpriority_queue
    priority_queue<P, vector<P>, greater<P>> que;
    // 距離をinfで初期化
    d.assign(N, INF);
    d[s] = 0;
    que.push({0, s});

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        //　戻る場合や他の方が早い場合は最短にならないので飛ばす
        if (d[v] < p.first)
            continue;

        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            // 他より早い場合は更新
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    G.resize(N);
    rep(i, N - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    ll Q, K;
    cin >> Q >> K;
    K--;
    dijkstra(K);
    rep(i, Q) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        cout << d[a] + d[b] << endl;
    }
}