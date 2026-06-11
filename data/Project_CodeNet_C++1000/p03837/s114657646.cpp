#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

struct Edge{
    int to;     //辺の行先
    ll cost; //辺の重み
    Edge(int t, ll w) : to(t), cost(w) {}
};

/* dijkstra(G,s,dis)
    入力:グラフ G, 開始点 s,距離を格納する dis
    計算量 : O(|E|log|V|)
    副作用 : disが書き換えられる
*/
using Graph = vector<vector<Edge>>;
using P = pair<ll,int>;
void dijkstra(const Graph &G, int s, int goal, vector<ll> &dis, vector<vector<int>> &prev){
    int N = G.size();
    dis.resize(N,INF);  // Gの大きさで初期化
    prev.resize(N);
    priority_queue<P,vector<P>,greater<P>> pq; // [仮の最短経路,頂点]が小さい順で並ぶ
    dis[s] = 0; //スタート地点の距離は0
    pq.emplace(dis[s],s); // スタート地点を代入
    while(!pq.empty()){
        P p = pq.top(); // 最短経路が一番小さいものを取得
        pq.pop();
        int V = p.second; // 頂点
        if(dis[V] < p.first){ // 最短経路で無い場合は無視
            continue;
        }
        if(V == goal) continue;
        for (auto &e : G[V]) {
            if(dis[e.to] >= dis[V] + e.cost) { //最短経路なら
                if(dis[e.to] > dis[V] + e.cost) prev[e.to].clear();
                dis[e.to] = dis[V] + e.cost;
                prev[e.to].push_back(V); //頂点vを通って　e.toにたどり着いた
                pq.emplace(dis[e.to],e.to);
            }
        }   
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    set<pair<int,int>> edge;
    Graph G(n+1);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
        edge.insert(make_pair(a,b));
    }
    for(int stt =0; stt < n-1; stt++){
        for(int goal = stt+1;goal < n;goal++){
            vector<ll> dis;
            vector<vector<int>> prev;
            dijkstra(G,stt,goal,dis,prev);
            queue<int> que;
            que.push(goal);
            while(!que.empty()){
                int v = que.front();
                que.pop();
                rep(i,prev[v].size()){
                    int vb = prev[v][i];
                    edge.erase({vb,v});
                    edge.erase({v,vb});
                    que.push(vb);
                }   
            }
        }

    }
    cout << edge.size() << endl;
    return 0;
}