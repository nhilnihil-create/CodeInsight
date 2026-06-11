#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

#define INF 1e+9
#define MAX_V 10

struct edge {
    int to;
    int cost;
};

// <最短距離, 頂点の番号>
using P = pair<int, int>;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;

        for(int i = 0; i < G[v].size(); ++i) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    string ans;
    for(int i = 0; i < s.size(); i++)
        if(i % 2 == 0) ans += s[i];
    cout << ans;
    return 0;
}
