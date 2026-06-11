#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL (1LL<<62) // 9223372036854775807
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
    void addEdge(long long s, long long d, long long w, long long c){
        node[s].emplace_back(s, d, w, c);
        node[d].emplace_back(d, s, w, c);
    }
};

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
    // 入力処理
    Init();
    ll n, m;
    cin >> n >> m;
    Graph g(n);
    vi a(m), b(m), c(m);
    rep(i, m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
        g.addEdge(a[i], b[i], c[i], i);
    }

    // 全点対最短距離の計算
    auto wf = WarshallFloyd(g);

    // 全点対について最短経路を復元して使用しない辺を洗い出す
    vector<bool> usedEdge(m, false);
    vector<vector<bool>> chk(n, vector<bool>(n, false));
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            // 既に探索済みの場合
            if(chk[i][j]) continue;
            
            // 現在位置
            queue<ll> pos;
            pos.push(j);

            // 始点iと現在位置の距離を元に、現在位置から移動できる先全てについて
            // その移動先への始点からの距離と現在位置からの距離を見比べて同じかチェック
            while(pos.size()){
                // キューの先頭を取り出す
                auto now = pos.front();
                pos.pop();
                // 既に探索済みの場合
                if(chk[i][now]) continue;
                // 始点にたどり着いていた場合にも抜ける
                if(now == i) continue;
                // 探索済みに変える
                chk[i][now] = true;
                // 経路の復元
                ll distStoN = wf[i][now];
                for(auto &edge: g.node[now]){
                    if(edge.weight == (distStoN - wf[i][edge.dst])){
                        pos.push(edge.dst);
                        usedEdge[edge.capacity] = true;
                    }
                }
            }
        }
    }

    // 答えの出力
    ll ans = 0;
    for(auto res: usedEdge) if(!res) ans++;
    cout << ans << endl;
}