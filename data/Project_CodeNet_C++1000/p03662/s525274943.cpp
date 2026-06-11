//----------------------------templates
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("tune=native")
    #pragma GCC target ("avx")
    //----------------------------
    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef unsigned long long ull;
    #define int ll

    #define FOR(i,j,n) for (int i=(int)(j);i<(n);i++)
    #define REP(i,n) for (int i=0;i<(int)(n);i++)
    #define REPS(i,n) for (int i=1;i<=(int)(n);i++)
    #define REPN(i,n) for (int i=(int)(n)-1;i>=0;i--)
    #define REPNS(i,n) for (int i=(int)(n);i>0;i--)

    #define I(n) scanf("%lld", &(n))
    #define LL(n) scanf("%lld", &(n))
    #define pb(n) push_back((n))
    #define mp(i,j) make_pair((i),(j))
    #define eb(i,j) emplace_back((i),(j))
    #define y0 y3487465
    #define y1 y8687969
    #define j0 j1347829
    #define j1 j234892
    #define uniq(v) v.erase( unique(v.begin(), v.end()), v.end() )

    #define all(x) (x).begin(),(x).end()

    typedef vector<int> vi;
    typedef pair<int,int> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;
    typedef vector<vpi> vvpi;
    typedef vector<vvi> vvvi;

    const int mod = 1000000007;

//--------------------------------------------

class UnionFind {
    private:
        vi par;    // x の親ノード
        vi rank;   // 木の高さ
        vi mem;    // メンバの数
        int sz;             // 集合の個数
    public:
        UnionFind(int n) :
            par(n, -1), rank(n, 0), mem(n, 1), sz(n) {
            REP(i,n) par[i] = i;
        }
    
    int size() { return sz; }

    // 集合の追加
    void makeset() {
        par.pb(par.size());
        rank.pb(0);
        mem.pb(1);
        sz++;
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);
    }

    int member(int x){
        x = find(x);
        return mem[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y]){
            par[x] = y;
            mem[y] += mem[x];
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
            mem[x] += mem[y];
        }
        sz--;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int n,a,b;
vvi edges;
vi visited, mainchain, sidechain;
deque<int> bfs,route;

signed main(){
    I(n);
    edges.resize(n+1);
    REP(i,n-1){
        I(a); I(b);
        edges[a].pb(b);
        edges[b].pb(a);
    }
    visited.resize(n+1);

    visited[1] = -1;
    bfs.pb(1);
    while(!bfs.empty()){
        auto node = bfs.front();
        bfs.pop_front();
        for (auto i: edges[node]){
            if (! visited[i]) {
                visited[i] = node;
                bfs.pb(i);
            }
        }
    }

    mainchain.resize(n+1);
    int node = n;
    while(node != 1){
        mainchain[node] = 1;
        route.push_front(node);
        node = visited[node];
    }
    route.push_front(1);
    mainchain[1] = 1; 
    UnionFind uf(n+1);
    REPS(i,n){
        for( auto v: edges[i]){
            if (!mainchain[i] || !mainchain[v]){
                uf.unite(i,v);
            }
        }
    }

    int fennec = 0;
    int snuke = 0;

    while( !route.empty() ){
        auto vf = route.front();
        cerr << vf << " ";
        route.pop_front();
        fennec += uf.member(vf);
        cerr << uf.member(vf) << endl;

        if (route.empty()) break;

        auto sf = route.back();
        cerr << sf << " ";
        route.pop_back();
        snuke += uf.member(sf);
                cerr << uf.member(sf) << endl;
    }
    cerr << fennec << " " << snuke << endl;
    cout << (fennec > snuke ? "Fennec" : "Snuke") << endl;
}