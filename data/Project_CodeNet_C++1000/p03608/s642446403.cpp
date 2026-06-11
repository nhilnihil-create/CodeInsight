#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

struct Edge{
    // 始点, 終点, 重み, 最大量
    long long src, dst, weight, capacity;
    Edge(): src(0), dst(0), weight(0), capacity(0) {}
    Edge(long long s, long long d, long long w): src(s), dst(d), weight(w) {}
    Edge(long long s, long long d, long long w, long long c): src(s), dst(d), weight(w), capacity(c) {}
};

class Graph{
public:
    long long size;
    vector<vector<Edge>> node;
    Graph(long long n): size(n), node(n) {}
    // 無向辺の追加
    void addEdge(long long s, long long d, long long w = 1){
        node[s].emplace_back(s, d, w);
        node[d].emplace_back(d, s, w);
    }
    // 有向辺の追加
    void addArc(long long s, long long d, long long w = 1){
        node[s].emplace_back(s, d, w);
    }
    // ノードの追加
    void addNode(){
        size++;
        node.emplace_back();
    }
};

// Warshall-Floyd; 全点間対最短路（ワーシャル-フロイド法）[O(n^3)]
vector<vector<long long>> WarshallFloyd(const Graph &g){
    const long long WeightINF = numeric_limits<long long>::max()/2-1;
    vector<vector<long long>> d(g.size, vector<long long>(g.size, WeightINF));
    for(long long v=0; v<g.size; v++){
        for(auto &edge: g.node[v]) d[edge.src][edge.dst] = edge.weight;
        d[v][v] = 0;
    }
    for(long long i=0; i<g.size; i++){
        for(long long j=0; j<g.size; j++){
            for(long long k=0; k<g.size; k++){
                if(d[j][i] != WeightINF && d[i][k] != WeightINF) d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    return d;
}

int main(){
    Init();

    // 初期値の入力
    ll n, m, r;
    cin >> n >> m >> r;
    Graph g(n);

    // 訪問箇所の入力（昇順に整列）
    vi city(r);
    rep(i, r){
        cin >> city[i];
        city[i]--;
    }
    sort(all(city));

    // グラフの作成（0-based）
    rep(i, m){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        g.addEdge(a, b, c);
    }

    // 全点間対最短路
    auto wf = WarshallFloyd(g);

    // 全探索
    ll ans = INFLL;
    do{
        // cityの順でした場合のコストを計算
        ll sum = 0;
        for(ll i=0; i<r-1; i++) sum += wf[city[i]][city[i+1]];
        chmin(ans, sum);
    } while(next_permutation(all(city)));
    cout << ans << endl;
}