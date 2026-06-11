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

template<typename T>
struct bellmanford{
    const T inf = numeric_limits<T>::max();
    ll N;
    vector<vector<pair<ll, T>>> G;
    vector<T> dist;
    vector<bool> negative;  // true:その頂点は負閉路によってコストが無限に小さくなる
    bool neg_cycle;

    bellmanford(vector<vector<pair<ll, T>>> _G): G(_G){
        N = G.size();
        dist.resize(N, inf);
        negative.resize(N, false);
        neg_cycle = false;
    }

    void init(ll start = 0){
        dist[start] = 0;
        
        // 経路更新
        for(int i = 0; i < N - 1; i++){
            for(int from = 0; from < N; from++){
                if (dist[from] == inf) continue;
                for(auto e: G[from]){
                    ll to; T cost;
                    tie(to, cost) = e;
                    if (dist[to] > dist[from] + cost){
                        dist[to] = dist[from] + cost;
                    }
                }
            }
        }

        // 閉路検出
        for (int i = 0; i < N; i++){
            for (int from = 0; from < N; from++){
                if (dist[from] == inf) continue;
                for(auto e: G[from]){
                    ll to; T cost;
                    tie(to, cost) = e;
                    if(dist[to] > dist[from] + cost){
                        dist[to] = dist[from] + cost;
                        negative[to] = true;
                    }
                    if (negative[from]) negative[to] = true;
                }
            }
        }
        
        // 負閉路が1つでも存在するならtrue
        neg_cycle = any_of(negative.begin(), negative.end(), [](bool x) { return x; });
    }
        
};

int main() {
    init();
    ll N, M;
    cin >> N >> M;
    vvc<pair<ll, ll>> G(N);
    rep(i,M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].eb(b, -c);
    }

    bellmanford<ll> bell(G);
    bell.init();
    if(bell.negative[N-1])
        cout << "inf" << endl;
    else
        cout << -bell.dist[N - 1] << endl;
}