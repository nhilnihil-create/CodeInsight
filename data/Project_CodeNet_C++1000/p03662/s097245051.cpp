#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

struct edge{int to, cost;};

class Graph
{
public:
    int V;
    vector<vector<edge>> G;
    vec d, root;

    Graph(int V): V(V){
        G = vector<vector<edge>>(V, vector<edge>(0));
        d = vec(V);
        root = vec(V);
    }

    void add_edge(int from, int to, int cost){
        G[from].push_back(edge({to, cost}));
    }

    void add_edge2(int v1, int v2, int cost){
        add_edge(v1, v2, cost);
        add_edge(v2, v1, cost);
    }

    void erase_edge(int from, int to){
        vec e(0);
        REP(i, G[from].size()){
            if(G[from][i].to == to) e.push_back(i);
        }
        IREP(i, e.size()) G[from].erase(G[from].begin() + e[i]);
    }

    void erase_edge2(int v1, int v2){
        erase_edge(v1, v2);
        erase_edge(v2, v1);
    }

    void dijkstra(int s, int t){
        priority_queue<Pii, vector<Pii>, greater<Pii>> que;
        fill(d.begin(), d.end(), INF);
        d[s] = 0;
        que.push(Pii(0, s));

        while(!que.empty()){
            Pii p = que.top(); que.pop();
            int v = p.second;
            if(v == t) return;
            if(d[v] < p.first) continue;
            REP(i, G[v].size()){
                edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(Pii(d[e.to], e.to));
                }
            }
        }
    }

    void dijkstra_r(int s, int t){
        priority_queue<Pii, vector<Pii>, greater<Pii>> que;
        fill(d.begin(), d.end(), INF);
        d[s] = 0; root[s] = -1;
        que.push(Pii(0, s));

        while(!que.empty()){
            Pii p = que.top(); que.pop();
            int v = p.second;
            if(v == t) return;
            if(d[v] < p.first) continue;
            REP(i, G[v].size()){
                edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    root[e.to] = v;
                    que.push(Pii(d[e.to], e.to));
                }
            }
        }
    }

    void bellman_ford(int s){
        fill(d.begin(), d.end(), INF);
        d[s] = 0;
        while(true){
            bool update = false;
            REP(v, V){
                REP(i, G[v].size()){
                    edge e = G[v][i];
                    if(d[v] != INF && d[e.to] > d[v] + e.cost){
                        d[e.to] = d[v] + e.cost;
                        update = true;
                    }
                }
            }
            if(!update) break;
        }
    }

    mat waeshall_floyd(){
        mat d2(V, vec(V));
        REP(i, V){
            REP(j, V){
                if(i == j){
                    d2[i][j] = 0;
                }else{
                    d2[i][j] = INF;
                }
            }
        }
        REP(v, V){
            REP(i, G[v].size()){
                edge e = G[v][i];
                d2[v][e.to] = e.cost;
            }
        }
        REP(k, V){
            REP(i, V){
                REP(j, V){
                    d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
                }
            }
        }
        return d2;
    }

};

signed main(){

    int N; cin >> N;
    Graph T(N);
    int a, b;
    REP(i, N - 1){
        cin >> a >> b;
        T.add_edge2(a - 1, b - 1, 1);
    }

    T.dijkstra_r(0, N - 1);

    vec root(1, N - 1);
    int now = N - 1;
    while(T.root[now] != -1){
        now = T.root[now];
        root.push_back(now);
    }

    REVERSE(root);
    int rootL = root.size();
    int v1 = root[(rootL - 1) / 2], v2 = root[(rootL - 1) / 2 + 1];

    T.erase_edge2(v1, v2);

    T.dijkstra(0, -1);

    int bnum = 0;
    REP(i, N) if(T.d[i] < INF) bnum++;
    
    if(bnum * 2 > N){
        cout << "Fennec";
    }else{
        cout << "Snuke";
    }
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}