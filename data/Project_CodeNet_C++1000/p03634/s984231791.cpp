#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

struct edge{
    int to;
    ll cost;
};
struct query{
    int from, to;
};

vector<vector<edge>> edges;
vector<ll> d;

void dfs(int vertex, ll cost, int parent=-1){
    d[vertex] = cost;
    for (auto e : edges[vertex]){
        if (e.to == parent) continue;
        dfs(e.to, cost + e.cost, vertex);        
    }
}

int main(){
    int N; cin >> N;
    d.assign(N,0);
    edges.resize(N);
    rep(i,N-1){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a].push_back(edge{b, c});
        edges[b].push_back(edge{a, c});
    }
    int Q, K; cin >> Q >> K;
    K--;
    vector<query> queries(Q);
    rep(i,Q){
        int from, to; cin >> from >> to;
        from--;
        to--;
        queries[i] = query{from, to};
    }
    
    dfs(K, 0);

    rep(i,Q){
        cout << d[queries[i].from] + d[queries[i].to] << endl;
    }
}