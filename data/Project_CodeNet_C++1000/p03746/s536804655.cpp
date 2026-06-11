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
typedef tuple<int,int,int> tpl;

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
constexpr double PI  = 3.141592653589793238462643383279;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353

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
    vector<pair<int,int>> i2e; // 辺番号から辺への変換

    Graph(int N): N(N) {
        adj.assign(N, vector<Edge<T>>());
        node.assign(N, Node<T>());
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    Graph() {}

    void add_edge(int i, int j, T cost=1, int id=-1){
        Edge<T> e(i, j, cost, id);
        if(id != -1) i2e.emplace_back(i, adj[i].size());
        adj[i].emplace_back(e);
    }

    vector<Edge<T>> get_adj(Node<T> node){
        return adj[node.id];
    }

    void assign(int n){
        N = n;
        adj.assign(N, vector<Edge<T>>());
        node.assign(N, Node<T>());
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    void reset(){
        for(int i=0; i<N; ++i){
            node[i].done = false;
            node[i].v = 1e9;
        }
    }
};

Graph<int> G;
VI path;

void dfs(int v){
    G.node[v].done = true;
    path.push_back(v);

    for(Edge<int>& e : G.adj[v]){
        if(G.node[e.to].done) continue;
        dfs(e.to);
        break;
    }
    return;
}

int main(void){
    int N,M; cin >> N >> M;
    G.assign(N);
    REP(i,M){
        int a,b; cin >> a >> b; a--; b--;
        G.add_edge(a,b);
        G.add_edge(b,a);
    }

    dfs(0);
    REVERSE(path);
    path.pop_back();
    dfs(0);

    cout << path.size() << en;
    REP(i,path.size()) cout << path[i]+1 << " ";
    cout << en;
    return 0;
}