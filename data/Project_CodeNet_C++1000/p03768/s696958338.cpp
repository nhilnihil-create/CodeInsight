#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
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

    Graph(int V): V(V){
        G = vector<vector<edge>>(V, vector<edge>(0));
    }

    void add_edge(int from, int to, int cost){
        G[from].push_back(edge({to, cost}));
    }

    void add_edge2(int v1, int v2, int cost){
        add_edge(v1, v2, cost);
        add_edge(v2, v1, cost);
    }

    void dfs(int v, int d, int i, vector<Pii> &ans){
        if(d <= ans[v].second) return;
        if(ans[v].first == -1) ans[v] = Pii(i, d);
        if(d > ans[v].second) ans[v].second = d;
        if(d > 0){
            REP(k, G[v].size()) dfs(G[v][k].to, d - 1, i, ans);
        }
    }

};

signed main(){

    int N, M; cin >> N >> M;
    Graph G(N);
    int a, b;
    REP(i, M){
        cin >> a >> b;
        G.add_edge2(a - 1, b - 1, 1);
    }
    int Q; cin >> Q;
    vec v(Q), d(Q), c(Q);
    REP(i, Q){
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }

    vector<Pii> ans(N, Pii(-1, -1));
    IREP(i, Q) G.dfs(v[i], d[i], i, ans);
    REP(i, N){
        if(ans[i].first == -1) cout << 0 << endl;
        else cout << c[ans[i].first] << endl;
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