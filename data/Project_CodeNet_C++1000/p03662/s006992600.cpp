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

#define MAX_V 100000
int V;
struct edge{int to, cost;};
vector<edge> G[MAX_V];

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

int d[MAX_V], b[MAX_V];
void dijkstra(int s, int t){
    priority_queue<Pii, vector<Pii>, greater<Pii>> que;
    fill(d, d + V, INF);
    d[s] = 0; b[s] = -1;
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
                b[e.to] = v;
                que.push(Pii(d[e.to], e.to));
            }
        }
    }
}

signed main(){

    int N; cin >> N; V = N;
    int A, B;
    REP(i, N - 1){
        cin >> A >> B;
        add_edge2(A - 1, B - 1, 1);
    }

    dijkstra(0, N - 1);

    vec root(1, N - 1);
    int now = N - 1;
    while(b[now] != -1){
        now = b[now];
        root.push_back(now);
    }

    REVERSE(root);
    int rootL = root.size();
    int v1 = root[(rootL - 1) / 2], v2 = root[(rootL - 1) / 2 + 1];

    erase_edge2(v1, v2);

    dijkstra(0, -1);

    int bnum = 0;
    REP(i, N) if(d[i] < INF) bnum++;
    
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