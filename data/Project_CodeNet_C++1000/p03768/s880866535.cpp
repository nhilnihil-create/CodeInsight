#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
struct Node{
    int id;
    T v;
    bool done = false;
    Node(int id, T v=1e9): id(id), v(v) {}
    Node(): id(0), v(1e9) {}
};

template<typename T>
struct Edge{
    int from, to, id;
    T cost;
    Edge(int from, int to, T cost=1, int id=-1): from(from), to(to), cost(cost), id(id) {}
};

template<typename T>
struct Graph{
    int N;
    vector<vector<Edge<T>>> adj;
    vector<Node<T>> node;

    Graph(int N): N(N) {
        adj.resize(N);
        node.resize(N);
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    Graph() {}

    void add_edge(int i, int j, T cost=1, int id=-1){
        Edge<T> e(i, j, cost, id);
        adj[i].emplace_back(e);
    }

    vector<Edge<T>> get_adj(Node<T> node){
        return adj[node.id];
    }

    void resize(int n){
        N = n;
        adj.resize(N);
        node.resize(N);
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    void init(T cost=1e9){
        for(int i=0; i<N; ++i){
            node[i].done = false;
            node[i].v = cost;
        }
    }
};

void Main(){
    int N,M; cin >> N >> M;
    Graph<int> G(N);
    REP(i,M){
        int a,b; cin >> a >> b; a--; b--;
        G.add_edge(a,b); G.add_edge(b,a);
    }

    int Q; cin >> Q;
    VI v(Q),d(Q),c(Q); REP(i,Q) cin >> v[i] >> d[i] >> c[i];

    int done = 0;
    VI ans(N,0), last(N,-1), vis;
    RREP(i,Q){
        v[i]--;
        if(d[i] <= last[v[i]]) continue;
        chmax(last[v[i]], d[i]);
        queue<tpl> q;
        q.emplace(v[i], 0);
        while(!q.empty()){
            int u, dep; tie(u, dep) = q.front(); q.pop();
            if(ans[u] == 0){
                ans[u] = c[i];
                done++;
            }
            if(done == N){
                REP(i,N) cout << ans[i] << en;
                return;
            }

            G.node[u].done = true;
            vis.push_back(u);
            if(dep == d[i]) continue;

            for(auto& e : G.adj[u]){
                if(G.node[e.to].done) continue;
                q.emplace(e.to, dep+1);
            }
        }
        while(!vis.empty()){
            G.node[vis.back()].done = false;
            vis.pop_back();
        }
    }
    REP(i,N) cout << ans[i] << en;
    return;
}

int main(void){
    cin.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t){
        Main();
    }
    return 0;
}