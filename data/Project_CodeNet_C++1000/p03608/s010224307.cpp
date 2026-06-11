/**
*	created: 11.09.2020 19:08:13
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
using ll = long long;
using P = pair<int,int>;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rrep(i,n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
template<typename T> inline bool chmax(T &a, T &b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> inline bool chmin(T &a, T &b) {if (b < a) {a = b; return 1;} return 0;}
template<typename T> T pow(T a, ll n) {T r(1); while(n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}
struct faster_io {faster_io() {cin.tie(0); ios_base::sync_with_stdio(false);}} faster_io_;

// Dijkstra's Algorithm
struct edge {int to, cost;};

struct graph {
    int n;
    vector<vector<edge>> G;
    vector<int> d, pre;
    graph(int i) : n(i), G(i), d(i,INF), pre(i) {}
    void add_edge(int s, int t, int cost) {
        edge e; e.to = t; e.cost = cost;
        G[s].push_back(e);
    }
    void dijkstra(int s) {
        rep(i,n) {d[i] = INF; pre[i] = 0;}
        d[s] = 0;
        priority_queue<P, vector<P>, greater<P>> que;
        que.push(P(0,s));
        while(!que.empty()){
            P p = que.top(); que.pop(); int v = p.second;
            if(d[v] < p.first) continue;
            for(auto e : G[v]) if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost; pre[e.to] = v;
                que.push(P(d[e.to],e.to));
            }
        }
    }
};
int dist[220][220]; // dist[i][j] : iからjまでの最短距離

signed main() {
    int n, m, r; cin >> n >> m >> r;
    graph g(n);
    vector<int> v(r);
    rep(i,r) {cin >> v[i]; v[i]--;}
    sort(all(v));
    rep(i,m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        g.add_edge(a,b,c);
        g.add_edge(b,a,c);
    }
    rep(i,r) {
        g.dijkstra(v[i]);
        rep(j,r) dist[v[i]][v[j]] = g.d[v[j]];
    }
    int ans = INF;
    do {
        int tmp = 0;
        rep(i,r-1) tmp += dist[v[i]][v[i+1]];
        chmin(ans,tmp);
    } while(next_permutation(all(v)));
    cout << ans << endl;
    return 0;
}