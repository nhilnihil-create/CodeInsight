#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int INF = 1e8;

struct edge { int to, cost; };
using ve = vector<edge>;

int N, M;

vector<ve> G(1010, ve());
vector<vi> dist(1010, vi(1010, INF));

void dijkstra(int s){
    // first:最短距離 second:頂点番号
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[s][s] = 0;
    q.push(pii(0, s));

    while (!q.empty()){
        int cur_d = q.top().first;
        int cur_v = q.top().second;
        //cout << cur_v << endl;
        q.pop();

        if (cur_d > dist[s][cur_v]) continue;

        for (int i = 0; i < G[cur_v].size(); i++){
            edge e = G[cur_v][i];
            if (dist[s][cur_v] + e.cost < dist[s][e.to]){
                dist[s][e.to] = dist[s][cur_v] + e.cost;
                q.push(pii(dist[s][e.to], e.to));
            }
        }
    }
}

int main(){
    cin >> N >> M;

    rep(i,N) dist[i][i] = 0;

    rep(i,M){
        int a, b, c; cin >> a >> b >> c; a--; b--;
        G[a].push_back(edge{b,c});
        G[b].push_back(edge{a,c});
    }

    rep(i,N) dijkstra(i);

    int ans = 2*M;
    rep(i,N) rep(j, G[i].size()){
        bool flag = false;
        //cout << i << " " << j << endl;
        rep(s,N){
            rep(t,N){
                if(dist[s][i] + G[i][j].cost + dist[G[i][j].to][t] == dist[s][t]){
                    ans--; flag = true;
                    break;
                }
            }
            if(flag) break;
        }
    }

    cout << ans/2 << endl;
}

