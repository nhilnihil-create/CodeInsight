#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define Rep(i, m, n) for(ll i = m; i < n; i++)
#define all(vec) vec.begin(), vec.end()
#define tmax(x, y, z) max((x), max((y), (z)))
#define tmin(x, y, z) min((x), min((y), (z)))
#define MINUS(a) memset(a, 0xff, sizeof(a))
#define ZERO(a) memset(a, 0, sizeof(a))
const ll INF = 1LL << 60;
const ll MM = 1000000000; const ll MOD = MM + 7; const ll MMM=9223372036854775807;//2^63 -1
#define ADD(a,b) a = (a + ll(b)) % MOD
#define MUL(a,b) a = (a * ll(b)) % MOD
ll GCD(ll x, ll y){ if(y == 0) return x; else return GCD(y, x % y);}
ll LCM(ll x, ll y){ return x / GCD(x, y) * y;}
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true;} return false;}
template<typename A, size_t N, typename T> void FILL(A (&array)[N], const T &val){ fill( (T*)array, (T*)(array+N), val );}
struct edge{ ll from, to, cost; };
// struct edge{ ll to, cost; };
// using Graph = vector<vector<ll>>;  // 重み無し
using Graph = vector<edge>;  // 辺
// using Graph = vector<vector<edge>>;  // 重み付き
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//cout << fixed << setprecision(10);

const ll MAX_E = 2000, MAX_V = 1000;  // 制約に従って決める
ll V, E;  // 入力で受け取る

Graph es(MAX_E);  // 0-basedにして順番に辺を入れる
ll d[MAX_V];  // ある頂点までの最短路(0-based)


bool bellman_ford(ll s){  // 始点の頂点番号が引数(0-based)
    FILL(d, INF);
    d[s] = 0;
    rep(loop, V-1){
        bool update = false;
        rep(i, E){
            edge e = es[i];
            if(d[e.from] != INF && chmin(d[e.to], d[e.from] + e.cost)) update = true;
        }
        // V-1回以内に更新無くなれば負の閉路なし
        if(!update) return true;
    }
    // もうV回回してV-1に更新がないか調べる
    rep(loop, V){
        bool update = false;
        rep(i, E){
            edge e = es[i];
            // 頂点V-1に更新があれば
            if(d[e.from] != INF && chmin(d[e.to], d[e.from] + e.cost) && e.to == V-1) update = true;
        }
        // 負の閉路があり無限に更新可能
        if(update) return false;
    }
    return true;
}


int main(){
    cin >> V >> E;
    rep(i, E){
        ll a, b, c; cin >> a >> b >> c; a--, b--, c = -c;
        es[i] = edge{a, b, c};
    }
    // 負の閉路なし
    if(bellman_ford(0)) cout << -d[V-1] << endl;
    else cout << "inf" << endl;
}
