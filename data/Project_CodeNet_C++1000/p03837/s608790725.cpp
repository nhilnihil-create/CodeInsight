#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;


#define MAX_V 100

struct edge {
    int to;
    int cost;
};

// <最短距離, 頂点の番号>
using P = pair<int, int>;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];
set<P> S;
vector<P> vec(MAX_V, P(0, 0));

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+MAX_V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                if(e.to<=v){
                  vec[e.to]=P(e.to, v);
                } else {
                  vec[e.to]=P(v, e.to);
                }
                que.push(P(d[e.to], e.to));
            }
        }
    }
    rep(i, MAX_V){
      if(vec[i]!=P(0, 0)){
        S.insert(vec[i]);
      }
    }
}

int main() {
    cin >> V;
    int E;
    cin >> E;
    for (int i=0; i<E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        //有向グラフ
        a--;b--;
        edge e = {b, c};
        G[a].push_back(e);
        edge e2 = {a, c};
        G[b].push_back(e2);
    }
    rep(i, V){
      dijkstra(i);
    }
    cout << (int)(E-S.size()) << endl;
    return 0;
}
