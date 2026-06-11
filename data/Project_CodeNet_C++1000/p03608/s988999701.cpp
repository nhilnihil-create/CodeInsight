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
// struct edge{ ll from, to, cost; edge(ll f, ll t, ll c) : from(f), to(t), cost(c) { } };
// struct edge{ ll to, cost; edge(ll t, ll c) : to(t), cost(c) { } };
// using Graph = vector<vector<ll>>;  // 重み無し
// using Graph = vector<vector<edge>>;  // 重み付き
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//cout << fixed << setprecision(10);

const ll MAX_V = 200;  // 最大頂点数(制約に従う)
ll d[MAX_V][MAX_V];  // 全体をINF、d[i][i]を0に初期化
// 初期化
// FILL(d, INF);
// rep(i, V) d[i][i] = 0;  // V: 実際の頂点数


// 0-basedに注意
void warshall_floyd(ll V){  // 実際の頂点数
    // 経由頂点, 始点, 終点
    rep(k, V) rep(i, V) rep(j, V) chmin(d[i][j], d[i][k] + d[k][j]);
}


int main(){
    ll n, m, r; cin >> n >> m >> r;
    vector<ll> vec(r);
    rep(i, r){
        ll ri; cin >> ri; ri--;  // 0-based
        vec[i] = ri;
    }

    // 初期化
    FILL(d, INF);
    rep(i, n) d[i][i] = 0;

    rep(i, m){
        ll a, b, c; cin >> a >> b >> c; a--, b--;  // 0-based
        // 無向
        d[a][b] = d[b][a] = c;
    }

    warshall_floyd(n);

    ll ans = INF;
    // next_permutationのため初期化
    sort(all(vec));
    do{
        ll sum = 0;
        rep(i, vec.size()-1) sum += d[vec[i]][vec[i+1]];
        chmin(ans, sum);
    }while(next_permutation(all(vec)));

    cout << ans << endl;
}
