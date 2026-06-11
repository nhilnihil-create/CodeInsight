#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

const ll INF = 1e9;

struct edge{
    int to;
    int cost;
};

vecveci dist(210,veci(100010,INF)); 
vector<vector<edge>> G(100010,vector<edge>());

void dijkstra(const vector<vector<edge>> &G, int s) {
    priority_queue<P,vector<P>,greater<P>> que;
    dist[s][s] = 0;
    que.push(P(0,s));

    while(!que.empty()) {
        P p1 = que.top();
        que.pop();
        int v = p1.second;
        if(dist[s][v] < p1.first) continue;

        for (auto e : G[v]) {  
            if (dist[s][e.to] > dist[s][v] + e.cost) {
                dist[s][e.to] = dist[s][v] + e.cost;
                que.push(P(dist[s][e.to], e.to));
            }
        }
    }
}

int main() {
    int N,M,R; cin >> N >> M >> R;
    veci r(R);
    REP(i,R) cin >> r[i];
    REP(i,R) r[i]--;
    REP(i,M) {
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }

    REP(i,R) {
        dijkstra(G,r[i]);
    }

    int ans = INF;

    sort(r.begin(),r.end());

    do{
        //REP(i,R) cout << r[i] << " ";
        //cout << endl;
        int total = 0;
        REP(i,R-1) {
            total += dist[r[i]][r[i+1]];
        }
        //cout << total << endl;
        chmin(ans,total);
    }while(next_permutation(r.begin(),r.end()));

    cout << ans << endl;
}
