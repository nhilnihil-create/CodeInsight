#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)
#define repa(i,n) for (auto& i: n)

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}

#ifdef DEBUG
template <class T, class N> void verr(const T& a, const N& n) { rep(i, n) cerr << a[i] << " "; cerr << "\n" << flush; }
ll dbgt = 1; void err() { cerr << "passed " << dbgt++ << "\n" << flush; }
template<class H, class... T> void err(H&& h,T&&... t){ cerr<< h << (sizeof...(t)?" ":"\n") << flush; if(sizeof...(t)>0) err(forward<T>(t)...); }
#endif

const ll INF = 5e18;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
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
    ll N,M,R;
    cin>>N>>M>>R;
    vc<ll> r(R);
    rep(i, R) cin >> r[i], r[i]--;
    vector<vector<ll>> G(N, vector<ll>(N,INF));
    rep(i,N) G[i][i]=0;
    
    rep(i,M){
        ll a,b,c;
        cin >> a >> b >> c;
        a--, b--;
        G[a][b] = G[b][a] = c;
    }

    warshall_floyd(G, INF);

    sort(all(r));

    ll ans = INF;
    do{
        ll tmp = 0;
        rep(i, R - 1) tmp += G[r[i]][r[i + 1]];
        chmin(ans, tmp);
    } while (next_permutation(all(r)));

    cout << ans << endl;
}