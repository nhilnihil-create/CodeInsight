#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
const ll INF = 1e16;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//
template <typename T>
void warshall_floyd(vector<vector<T>> &g, T inf) {
    rep(k, g.size()) {
        rep(i, g.size()) {
            rep(j, g.size()) {
                if (g[i][k] == inf || g[k][j] == inf) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

/*
vector<vector<ll>> G(V, vector<ll>(V,INF));
rep(i,V) G[i][i]=0;
rep(i,E)G[from][to]=cost;
warshall_floyd(G, )
*/
int main() {
    init();
    ll N, M;
    cin >> N >> M;
    vvc<ll> COST(N,vl(N,INF)),G(N, vl(N, INF));
    rep(i, N) G[i][i] = 0;
    rep(i,M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        COST[a][b] = c;
        COST[b][a] = c;
        G[a][b] = c;
        G[b][a] = c;
    }

    warshall_floyd(G, INF);

    ll ans = 0;
    rep(i,N-1)repe(j,i+1,N){
        if (COST[i][j] == INF) continue;

        if (COST[i][j] != G[i][j]) ans++;
    }

    cout << ans << endl;
}