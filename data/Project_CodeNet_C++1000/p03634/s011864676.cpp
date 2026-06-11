#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

using P = pair<ll, ll>;
const int V = 100010;
vector<P> G[V]; // pair<辺の距離, 行き先の頂点> (隣接リスト)
ll dist[V]; // dist[i]はsから頂点iへの最短距離が入る
bool used[V];
void dijkstra(ll s) { // s: 始点
    fill_n(dist, V, 1000000000000000);
    fill_n(used, V, false);
    priority_queue<P, vector<P>, greater<P>> q; // 値が小さい順に取り出されるpriority_queue
    q.push(P(0, s));
    while(!q.empty()) {
        ll d, t; // d: sからの距離 t: 行き先
        tie(d, t) = q.top(); q.pop();
        if (used[t]) continue; // 既に探索済か
        used[t] = true; dist[t] = d;
        for(P e: G[t]){
            if(dist[e.second] <= d+e.first) continue;
            q.push(P(d+e.first, e.second));
        }
    }
}

int main(){
    int N;
    cin >> N;
    N--;
    rep(i, N){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(make_pair(c, b));
        G[b].push_back(make_pair(c, a));
    }
    int Q, K;
    cin >> Q >> K;
    K--;
    vector<int> x(Q), y(Q);
    rep(i, Q){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }

    dijkstra(K);
    for(int i = 0; i < Q; i++){
        cout << dist[x[i]] + dist[y[i]] << endl;
    }

    return 0;
}
