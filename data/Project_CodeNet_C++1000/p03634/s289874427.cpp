#include <bits/stdc++.h>
using namespace std;

// def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (a); i < (b); i++)
#define revrepeat(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define foreach(e, v) for (auto &e : v)
#define all(x) (x).begin(), (x).end()
#define CYES cout << "Yes" << endl
#define CNO cout << "No" << endl
#define SPC(x) cout << fixed << setprecision(x)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vector<ll>> vll;
typedef pair<int, int> P;
typedef complex<ld> Point;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX_V = 1e5 + 5;
const int MAX_N = 1e5 + 5;
const double PI = acos(-1);

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// make vector of divisor O(sqrt(n))
vector<long long> divisor(long long n) {
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}
bool is_prime(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1; // exclude 1
}

// factorization O(sqrt(n))
map<long long, long long> prime_factor(long long n) {
    map<long long, long long> res;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}
// https://qiita.com/drken/items/cce6fc5c579051e64fab
// UnionFind<int> uf(n);
template <class Abel>
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> size;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n);
        rank.resize(n);
        size.resize(n);
        diff_weight.resize(n);
        for (int i = 0; i < n; ++i)
            par[i] = i, rank[i] = 0, size[i] = 1, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]]; // path compression
            return par[x] = r;
        }
    }
    // returns size of connected-tree number
    int get_size(int x) {
        return size[root(x)];
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool is_same(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        size[x] = size[y] = size[x] + size[y];
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

struct Edge {
    int to;
    ll cost;
};
ll d[100009];
bool seen[100009];
void dfs(int k, ll prev, vector<vector<Edge>> &G) {
    seen[k] = true;
    foreach (e, G[k]) {
        if (seen[e.to]) continue;

        d[e.to] = prev + e.cost;
        dfs(e.to, prev + e.cost, G);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<Edge>> Graph(n);
    rep(i, n - 1) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        Graph[a].push_back(Edge{b, c});
        Graph[b].push_back(Edge{a, c});
    }
    int q, k;
    cin >> q >> k;
    k--;

    dfs(k, 0, Graph);
    rep(i, q) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        out(d[x] + d[y]);
    }
}
