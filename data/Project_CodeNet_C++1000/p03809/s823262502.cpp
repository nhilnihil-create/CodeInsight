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
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }

struct edge{int to, cost;};

class Graph
{
public:
    int V;
    vector<vector<edge>> G;

    vec gen, par;
    mat chi, genlist;
    int depth;

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

    void dfs(int v, int d){
        gen[v] = d;
        depth = max(depth, d + 1);
        REP(k, G[v].size()){
            if(G[v][k].to == par[v]) continue;
            par[G[v][k].to] = v;
            chi[v].push_back(G[v][k].to);
            dfs(G[v][k].to, d + 1);
        }
    }

    mat makegenlist(){
        REP(v, V) genlist[gen[v]].push_back(v);
        return genlist;
    }

    void analyzeTree(int root){
        gen = vec(V); par = vec(V);
        chi = mat(V, vec(0));
        depth = 0;
        par[root] = -1;
        dfs(root, 0);

        genlist = mat(depth, vec(0));
        makegenlist();
    }

};

signed main(){

    int N; cin >> N;
    vec A(N); readv(A);
    int a, b;
    Graph T(N);
    REP(i, N - 1){
        cin >> a >> b;
        T.add_edge2(a - 1, b - 1, 0);
    }

    if(N == 2){
        if(A[0] == A[1]) cout << "YES";
        else cout << "NO";
        return 0;
    }

    int root;
    REP(v, N) if(T.G[v].size() > 1) root = v;
    T.analyzeTree(root);

    bool ans = true;
    IREP(d, T.depth){
        for(int v: T.genlist[d]){
            if(T.chi[v].size() == 0){
                continue;
            }else if(T.chi[v].size() == 1){
                if(A[v] != A[T.chi[v][0]]){
                    ans = false;
                    break;
                }
            }else{
                int s = 0, m = -1;
                for(int chi: T.chi[v]){
                    s += A[chi];
                    m = max(m, A[chi]);
                }
                int n;
                if(2 * m <= s) n = s / 2;
                else n = s - m;
                int dif = s - A[v];
                if(0 <= dif && dif <= n){
                    A[v] -= dif;
                }else{
                    ans = false;
                    break;
                }
            }
        }
        if(!ans) break;
    }
    if(ans && A[root] == 0) cout << "YES";
    else cout << "NO";
    
    return 0;
}