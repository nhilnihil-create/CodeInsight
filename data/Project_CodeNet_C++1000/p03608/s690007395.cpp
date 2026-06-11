/**
*	created: 11.09.2020 21:25:54
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
template<typename T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> inline bool chmin(T &a, T b) {if (b < a) {a = b; return 1;} return 0;}
template<typename T> T pow(T a, ll n) {T r(1); while(n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}
struct faster_io {faster_io() {cin.tie(0); ios_base::sync_with_stdio(false);}} faster_io_;

// Floyd-Warshall Algorithm
struct graph{
    int n; 
    vector<vector<int>> m;
    graph(int i) : n(i), m(i,vector<int>(i,INF)) {
        rep(i,n) m[i][i] = 0;
    }
    void add_edge(int a, int b, int cost) {
        chmin(m[a][b], cost);
        chmin(m[b][a], cost);
    }
    void floyd_warshall() {
        rep(k,n) rep(i,n) rep(j,n) chmin(m[i][j], m[i][k] + m[k][j]);
    }
};

signed main() {
    int n, m, r; cin >> n >> m >> r;
    vector<int> v(r);
    rep(i,r) {cin >> v[i]; v[i]--;}
    sort(all(v));
    graph g(n);
    rep(i,m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        g.add_edge(a,b,c);
    }
    g.floyd_warshall();
    int ans = INF;
    do {
        int tmp = 0;
        rep(i,r-1) tmp += g.m[v[i]][v[i+1]]; 
        chmin(ans,tmp);
    } while(next_permutation(all(v)));
    cout << ans << endl;
    return 0;
} 