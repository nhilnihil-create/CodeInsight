#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (int i = m; i < (n); ++i)
using namespace std;
using ll = long long;

ll N, M, S, A[500009], B[500009], C[500009];
ll dist[100009];
vector<pair<ll, ll>> G[100009];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;

void dijkstra(int S){
    // 距離を初期化する
    for (int i = 1; i <= N; i++) dist[i] = 1e18;

    // 優先度付きキューには (距離, 頂点番号) の組を入れる
    Q.push(make_pair(0, S));
    dist[S] = 0;
    while (!Q.empty()) {
        ll pos = Q.top().second; Q.pop();
        for (int i = 0; i < G[pos].size(); i++) {
            ll to = G[pos][i].first, cost = G[pos][i].second;
            if (dist[to] > dist[pos] + cost) {
                dist[to] = dist[pos] + cost;
                Q.push(make_pair(dist[to], to));
            }
        }
    }
    /*
    // 始点からの距離を出力する
    for (int i = 1; i <= N; i++) cout << dist[i] << " ";
    cout << endl;
    */
}

int main() {
    // <無向>グラフを入力する 頂点N 辺M 番号は1~
    cin >> N; M = N-1;
    //scanf("%d%d", &N, &M);
    // 頂点A,B間の距離C
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        //scanf("%d%d%d", &A[i], &B[i], &C[i]);
        G[A[i]].push_back(make_pair(B[i], C[i]));
        G[B[i]].push_back(make_pair(A[i], C[i]));
    }
    /*
    // 始点をすべて試す
    repp(s,N+1,1){
        dijkstra(s);
    }
    */
    int q, k; cin >> q >> k;
    dijkstra(k);
    vector<vector<int>> ar(q, vector<int>(2));
    rep(i,q) cin >> ar[i][0] >> ar[i][1];
    rep(i,q) cout << dist[ar[i][0]] + dist[ar[i][1]] << endl;
}