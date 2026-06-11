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
typedef pair<Pii, int> PPi;

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

    void dfs(int v, int g, vec &group){
        if(group[v] != -1) return;
        group[v] = g;
        REP(k, G[v].size()) dfs(G[v][k].to, g, group); 
    }

};

signed main(){

    int N, K, L;
    cin >> N >> K >> L;
    int p, q;
    Graph R(N), T(N);
    REP(i, K){
        cin >> p >> q;
        R.add_edge2(p - 1, q - 1, 0);
    }
    REP(i, L){
        cin >> p >> q;
        T.add_edge2(p - 1, q - 1, 0);
    }

    vec groupR(N, -1), groupT(N, -1);
    vector<PPi> group(N);

    int g = 0;
    REP(i, N){
        if(groupR[i] == -1){
            R.dfs(i, g, groupR);
            g++;
        }
    }
    g = 0;
    REP(i, N){
        if(groupT[i] == -1){
            T.dfs(i, g, groupT);
            g++;
        }
    }

    REP(i, N) group[i] = PPi(Pii(groupR[i], groupT[i]), i);
    SORT(group);

    vec ans(N);
    int s = 0, n = 1;
    REP(i, N){
        if(i == N - 1 || group[i].first != group[i + 1].first){
            FOR(j, s, i + 1) ans[group[j].second] = n;
            s = i + 1;
            n = 1;
        }else{
            n++;
        }
    }
    REP(i, N) cout << ans[i] << " ";
    
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