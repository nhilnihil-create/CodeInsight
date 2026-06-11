#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

// SegTreeLazyProportional<X,M>(n,fx,fa,fm,fp,ex,em)
// モノイド(集合X, 二項演算fx,fa,fm,fp, 単位元ex,em) についてサイズnで構築
// set(int i, X x), build()
// : i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
// update(i,x)
// : i番目の要素を x に更新。O(log(n))
// query(a,b)
// : [a,b) 全てにfxを作用させた値を取得。O(log(n))

// 二項演算
// fx : メインで用いる関数 (RMQならmin, RSQならx1+x2)
// fa : 遅延評価をもとに更新する際の関数   (RUQならm, RAQならx+m)
// fm : 遅延評価木上で子に伝播する際の関数 (RUQならm2, RAQならm1+m2)
// fp : 遅延評価木上で子に伝播する際に、区間長nに対して親の変化を表す関数
//      (RSQなら m * n)

// 単位元
// ex : datにデフォルトで乗る値（最小値取得の場合はINF, 区間和の場合は0）
// em : lazyにデフォルトで乗る値（区間更新の場合はINF, 区間加算の場合は0）

// ---------------------------------------------------------
// RMQ + RUQ
// : 区間更新を行い Range Updated Query (RUQ)、
// : 区間上の最小値 Range Minimam Query (RMQ) を取得する場合

// using X = int;
// using M = int;
// auto fx = [](X x1, X x2) -> X { return min(x1, x2); };
// auto fa = [](X x, M m) -> X { return m; };
// auto fm = [](M m1, M m2) -> M { return m2; };
// auto fp = [](M m, long long n) -> M { return m; };
// int ex = numeric_limits<int>::max();
// int em = numeric_limits<int>::max();
// SegTreeLazyProportional<X, M> rmq(n, fx, fa, fm, fp, ex, em);

// ---------------------------------------------------------
// RMQ + RAQ
// : 区間加算を行い Range Added Query (RAQ)、
// : 区間上の最小値 Range Minimum Query (RMQ) を取得する場合

// using X = int;
// using M = int;
// auto fx = [](X x1, X x2) -> X { return min(x1, x2); };
// auto fa = [](X x, M m) -> X { return x + m; };
// auto fm = [](M m1, M m2) -> M { return m1 + m2; };
// auto fp = [](M m, long long n) -> M { return m; };
// int ex = numeric_limits<int>::max();
// int em = 0;
// SegTreeLazyProportional<X, M> rmq(n, fx, fa, fm, fp, ex, em);

// // 区間加算の場合はデフォルト値を0にセットしておくこと
// rep(i, n) rmq.set(i, 0);
// rmq.build();

// ---------------------------------------------------------
// RSQ + RAQ
// : 区間加算を行い Range Added Query (RAQ)、
// : 区間和 Range Sum Query (RSQ) を取得する場合

// using X = int;
// using M = int;
// auto fx = [](X x1, X x2) -> X { return x1 + x2; };
// auto fa = [](X x, M m) -> X { return x + m; };
// auto fm = [](M m1, M m2) -> M { return m1 + m2; };
// auto fp = [](M m, long long n) -> M { return m * n; };
// int ex = 0;
// int em = 0;
// SegTreeLazyProportional<X, M> rmq(n, fx, fa, fm, fp, ex, em);

// // 区間加算の場合はデフォルト値を0にセットしておくこと
// rep(i, n) rmq.set(i, 0);
// rmq.build();

template <typename X, typename M>
struct SegTreeLazyProportional {
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    using FP = function<M(M, ll)>;
    ll n;
    FX fx;
    FA fa;
    FM fm;
    FP fp;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    SegTreeLazyProportional(ll n_, FX fx_, FA fa_, FM fm_, FP fp_, X ex_, M em_)
        : n(),
          fx(fx_),
          fa(fa_),
          fm(fm_),
          fp(fp_),
          ex(ex_),
          em(em_),
          dat(n_ * 4, ex),
          lazy(n_ * 4, em) {
        ll x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void set(ll i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (ll k = n - 2; k >= 0; k--)
            dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    /* lazy eval */
    void eval(ll k, ll len) {
        if (lazy[k] == em) return;  // 更新するものが無ければ終了
        if (k < n - 1) {            // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
        }
        // 自身を更新。子はしばらく放置
        dat[k] = fa(dat[k], fp(lazy[k], len));
        lazy[k] = em;
    }

    void update(ll a, ll b, M x, ll k, ll l, ll r) {
        eval(k, r - l);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = fm(lazy[k], x);
            eval(k, r - l);
        } else if (a < r && l < b) {  // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(ll a, ll b, M x) { update(a, b, x, 0, 0, n); }

    X query_sub(ll a, ll b, ll k, ll l, ll r) {
        eval(k, r - l);
        if (r <= a || b <= l) {  // 完全に外側の時
            return ex;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    X query(ll a, ll b) { return query_sub(a, b, 0, 0, n); }

    // [a, b)でx以下の要素を持つ最右位置はどこか
    X find_rightest(int a, int b, int x) {
        return find_nearest_sub(a, b, x, 0, 0, n, true);
    }

    // [a, b)でx以下の要素を持つ最左位置はどこか
    X find_leftest(int a, int b, int x) {
        return find_nearest_sub(a, b, x, 0, 0, n, false);
    }

    X find_nearest_sub(int a, int b, int x, int k, int l, int r,
                       bool is_right) {
        eval(k, r - l);
        if (dat[k] > x || r <= a ||
            b <= l) {  // 自分の値がxより大きい or
                       // [a,b)が[l,r)の範囲外ならreturn -1
            return -1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            if (is_right) {
                int vr = find_nearest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r,
                                          is_right);
                if (vr != -1) {  // 右の部分木を見て-1以外ならreturn
                    return vr;
                } else {  // 左の部分木を見て値をreturn
                    return find_nearest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2,
                                            is_right);
                }
            } else {
                int vl = find_nearest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2,
                                          is_right);
                if (vl != -1) {  // 左の部分木を見て-1以外ならreturn
                    return vl;
                } else {  // 右の部分木を見て値をreturn
                    return find_nearest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r,
                                            is_right);
                }
            }
        }
    }

    // debug
    inline X operator[](int a) { return query(a, a + 1); }
    void print() {
        for (ll i = 0; i < n; ++i)
            cout << ((*this)[i] == ex ? "ex" : to_string((*this)[i])) << ", ";
        cout << endl;
    }

    void print_dat() {
        cout << "[dat ] ";
        for (ll i = 0; i < 2 * n - 1; ++i)
            cout << (dat[i] == ex ? "ex" : to_string(dat[i])) << ", ";
        cout << endl;
    }

    void print_lazy() {
        cout << "[lazy] ";
        for (ll i = 0; i < 2 * n - 1; ++i)
            cout << (lazy[i] == em ? "em" : to_string(lazy[i])) << ", ";
        cout << endl;
    }
};

int main() {
    INIT;

    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    using X = ll;
    using M = ll;
    auto fx = [](X x1, X x2) -> X { return min(x1, x2); };
    auto fa = [](X x, M m) -> X { return m; };
    auto fm = [](M m1, M m2) -> M { return m2; };
    auto fp = [](M m, ll n) -> M { return m; };
    ll ex = numeric_limits<ll>::max();
    ll em = numeric_limits<ll>::max();
    SegTreeLazyProportional<X, M> rmq(N, fx, fa, fm, fp, ex, em);

    rep(i, N) rmq.set(i, a[i]);
    rmq.build();

    // rmq.print_dat();

    ll ans = 0;
    rep(i, N) {
        ll l = rmq.find_rightest(0, i, a[i]) + 1;
        ll r = rmq.find_leftest(i + 1, N, a[i]);
        if (r == -1) r = N;
        ans += (i - l + 1) * (r - i) * a[i];
        // cout << l << ", " << r << endl;
    }

    // rep(l, N) {
    //     // cout << "--- " << l << " ---" << endl;
    //     ll m, idx = N;
    //     while (idx > l) {
    //         m = rmq.query(l, idx);

    //         ll tmp = rmq.find_rightest(l, idx, m);
    //         ans += m * (idx - tmp);

    //         // cout << m << ", " << tmp << "->" << ans << endl;
    //         idx = tmp;
    //     }
    // }

    cout << ans << endl;

    return 0;
}