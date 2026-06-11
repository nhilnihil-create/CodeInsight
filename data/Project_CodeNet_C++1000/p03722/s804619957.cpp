#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
//constexpr int INF = 1001001001;
constexpr ll INF = 1001001001001001001ll;
constexpr double EPS = 1e-10;
using number = long long;




struct edge {
    int from, to;
    number cost;
    edge(int a, int b, number c) : from(a), to(b), cost(c) {}
};


using Edges = vector< edge >;

vector< number > bellman_ford(int s, int V, vi &prev, const Edges &edges) {
    vector< number > dist(V, INF);
    prev.assign(V, -2);
    dist[s] = 0;
    for (int i = 0; i < V; i++) {
        for (auto &e : edges) {
            if (dist[e.from] == INF) continue;
            if (dist[e.from] + e.cost < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.cost;
                prev[e.to] = e.from;
                if (i == V - 1) dist[e.to] = - INF;
            }
        }
    }
    return dist;
}


int main() {
    int N, M; cin >> N >> M;
    Edges G;
    int a, b; ll c;
    rep(i, M) {
        cin >> a >> b >> c;
        a--, b--;
        G.pb(edge(a, b, -c));
    }
    vi prev(N);

    vll dist = bellman_ford(0, N, prev, G);

    bool can = false;
    int v = N - 1;
    rep(i, N) {
        v = prev[v];
        if(v == -2){
            can = true;
            break;
        }
    }

    if(can) cout << -dist[N - 1] << endl;
    else cout << "inf" << endl;

}