#include <bits/stdc++.h>
using namespace std;

//def
#define debug(x) cout << #x << ": " << x << '\n'
#define out(x) cout << x << '\n'
#define repeat(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define revrepeat(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
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
constexpr int MOD = 1e9 + 7;
constexpr int INF = __INT_MAX__;               // 2^31 - 1
constexpr long long INFLL = __LONG_LONG_MAX__; // 2^61 - 1
constexpr int MAX_N = 1e5 + 5;
constexpr double PI = acos(-1);

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

long long fac[MAX_N], finv[MAX_N], inv[MAX_N];
// テーブルを作る前処理 from: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX_N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long modpow(long long m, long long p) {
    if (p == 0) return 1;
    if (p % 2)
        return m * modpow(m, p - 1) % MOD;
    else {
        long res = modpow(m, p / 2);
        return res * res % MOD;
    }
}
// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// factorial
long long fact(int n) {
    if (n == 1) return fac[n] = 1;
    if (fac[n]) return fac[n];
    return fac[n] = (fact(n - 1) * n) % MOD;
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
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
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

// 回文判定
bool is_palindrome(string const &s) {
    return s == string(s.rbegin(), s.rend());
}

vi ans(100005);
vi seen(100005);
void dfs(int curr, int prev, int color, int color_size, vii &node, map<P, int> &dict) {
    seen[curr] = true;
    ans[dict[P(curr, prev)]] = color;
    foreach (e, node[curr]) {
        if (!seen[e]) {
            color++;
            if (color > color_size) color = 1;
            dfs(e, curr, color, color_size, node, dict);
        }
    }
}

vll dp(105, vl(2, 0));
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;
    vi a(n);
    rep(i, n) cin >> a[i];

    dp[0][0] = 1;
    rep(i, n) {
        if (a[i] % 2 == 0) {
            dp[i + 1][0] += 2 * dp[i][0];
            dp[i + 1][1] += 2 * dp[i][1];
        } else {
            dp[i + 1][0] += dp[i][0] + dp[i][1];
            dp[i + 1][1] += dp[i][0] + dp[i][1];
        }
    }

    out(dp[n][p]);
}
