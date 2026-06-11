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

struct Edge {
    ll to, rev;
    long double cap;
    Edge(ll _to, long double _cap, ll _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph &G, ll from, ll to, long double cap, bool revFlag,
              long double revCap) {
    G[from].push_back(Edge(to, cap, (ll)G[to].size()));
    if(revFlag)
        G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

template <typename T, typename F>
class SegmentTree {
  private:
    T e;
    F op;
    ll n;
    vector<T> dat;

  public:
    SegmentTree(F f, T _e, vector<T> v) : op(f), e(_e) {
        int _n = v.size();
        n = 1;
        while(n < _n)
            n *= 2;
        dat.resize(2 * n - 1, e);
        REP(i, _n)
        dat[n + i - 1] = v[i];
        for(int i = n - 2; i >= 0; i--)
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
    SegmentTree(F f, T _e, int _n) : op(f), e(_e) {
        n = 1;
        while(n < _n)
            n *= 2;
        dat.resize(2 * n - 1, e);
        for(int i = n - 2; i >= 0; i--)
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
    void update(int i, T x) {
        i += n - 1;
        dat[i] += x;
        while(i > 0) {
            i = (i - 1) / 2;
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    T query(int l, int r) {
        //[l,r)でのクエリ処理
        T left = e, right = e;
        l += n - 1;
        r += n - 1;
        while(l < r) {
            if((l & 1) == 0)
                left = op(left, dat[l]);
            if((r & 1) == 0)
                right = op(dat[r - 1], right);
            l = l / 2;
            r = (r - 1) / 2;
        }
        return op(left, right);
    }
};

void solve() {
    ll n, k;
    cin >> n >> k;
    vec<ll> a(n);
    REP(i, n) { cin >> a[i]; }

    auto op = [](ll a, ll b) { return a + b; };
    SegmentTree<ll, decltype(op)> seg(op, 0, n * 2 + 1);

    ll summ = 0;
    vec<ll> sum(n);
    map<ll, ll> mp;
    REP(i, n) {
        summ += a[i] - k;
        sum[i] = summ;
        mp[summ]++;
    }
    mp[0]++;
    int id = 0;
    for(auto &i : mp) {
        i.second = id;
        id++;
    }

    ll ans = 0;
    seg.update(mp[0], 1);
    REP(i, n) {
        ans += seg.query(0, mp[sum[i]] + 1);
        seg.update(mp[sum[i]], 1);
    }
    cout << ans << en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    /*
    ll t;
    cin >> t;
    REP(i, t)
    solve();
    */

    return 0;
}
