#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
//const int INF = 2e9;
const ll INF = 9e18;
struct Edge {int to, cost;};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<Edge>> g(N);
    vector<int> dist(N,INF);
    vector<bool> visited(N,false);
    for (int i=0;i<N-1;i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        Edge e1;
        e1.to = b;
        e1.cost = c;
        Edge e2;
        e2.to = a;
        e2.cost = c;
        g[a].push_back(e1);
        g[b].push_back(e2);
    }
    int Q, K;
    cin >> Q >> K;
    K--;
    dist[K] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(make_pair(0,K));
    while (!q.empty()){
        pair<int,int> p = q.top();q.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto e : g[v]){
            if (dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                q.push(make_pair(dist[e.to],e.to));
            }
        }
    }
    for (int i=0;i<Q;i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        cout << dist[x] + dist[y] << "\n";
    }
}