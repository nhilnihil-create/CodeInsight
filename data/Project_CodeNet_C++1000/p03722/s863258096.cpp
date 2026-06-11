//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

// 辺を表す構造体
struct edge{
    int from, to;
    long long cost;
};


// v:=頂点数 es:=辺の集合 cost:=始点からの最短経路のコストを格納する配列
// s:=始点(指定しなければ頂点0) g:=終点(指定しなければ頂点v-1)
// 始点から到達可能で、かつ終点へ到達可能な負閉路が検出された場合falseを、それ以外の場合trueを返す
bool bellman_ford(int v, const vector<edge>& es, vector<long long>& cost, int s = 0, int g = -1){
    if(g == -1){
        g = v - 1;
    }

    constexpr long long INF = 1LL << 61;

    cost.assign(v, INF);
    cost[s] = 0;

    for(int i = 0 ; i < v * 2 ; ++i){
        for(auto& e : es){
            if(cost[e.from] < INF && cost[e.from] + e.cost < cost[e.to]){
                if(i >= v - 1 && e.to == g){
                    return false;
                }else if(i >= v - 1){
                    cost[e.to] = -INF;
                }else{
                    cost[e.to] = cost[e.from] + e.cost;
                }
            }
        }
    }

    return true;
}

int main(){
    ll N,M;
    cin>>N>>M;
    vector<edge> G;
    vector<ll> cost(N);
    int a,b;
    ll c;
    REP(i,M){
        cin>>a>>b>>c;
        a--;
        b--;
        c=-c;
        G.push_back({a,b,c});
    }

    if(!bellman_ford(N,G,cost,0,N-1)){
        cout<<"inf"<<endl;
    }else{
        cout<<-cost[N-1]<<endl;
    }
}