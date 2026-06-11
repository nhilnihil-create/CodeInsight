#include <bits/stdc++.h>
using namespace std;

#define rep(i, m, n) for(int(i) = (int)(m); i < (int)(n); ++i)
#define rep2(i, m, n) for(int(i) = (int)(n)-1; i >= (int)(m); --i)
#define REP(i, n) rep(i, 0, n)
#define REP2(i, n) rep2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
using tp = tuple<ll, ll, ll>;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
//constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
typedef vector<ll> Array;
typedef vector<Array> Matrix;

template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

//グラフ関連
struct Edge {
    ll to, cap, rev;
    Edge(ll _to, ll _cap, ll _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph &G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
    G[from].push_back(Edge(to, cap, (ll)G[to].size()));
    if(revFlag)
        G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

class UnionFind {
    vector<int> data;
    int num;

  public:
    UnionFind(int size) : data(size, -1), num(size) {}
    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);
        if(x != y) {
            if(data[y] < data[x])
                swap(x, y);
            data[x] += data[y];
            data[y] = x;
            num--;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
    int numSet() {
        return num;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    UnionFind uni(n);
    UnionFind ni(2 * n); //二部グラフ判定

    REP(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        uni.unionSet(a, b);
        ni.unionSet(a, b + n);
        ni.unionSet(b, a + n);
    }

    ll con1 = 0;
    ll con2 = 0; //二部グラフ
    ll con3 = 0;
    ll ans = 0;
    REP(i, n) {
        if(uni.root(i) != i)
            continue;
        if(uni.size(i) == 1) {
            //孤立点
            con1++;
            ans += (n - con1) * 2 + 1;
            continue;
        }
        if(ni.root(i) != ni.root(i + n)) {
            //二部グラフ
            con2++;
        } else {
            con3++;
        }
    }

    ans += con3 * con3;
    ans += con3 * con2 * 2;
    ans += con2 * con2 * 2;

    cout << ans << en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*
    ll t;
    cin >> t;
    while(t--)*/
    solve();

    return 0;
}
