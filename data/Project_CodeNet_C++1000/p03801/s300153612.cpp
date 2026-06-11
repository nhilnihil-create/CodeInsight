#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 2100100100;
const int MOD = 1e9 + 7;

/* SegTree<X>(n,fx,ex): モノイド(集合X, 二項演算fx, 単位元ex)についてサイズnで構築
    set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b):  [a,b) 全てにfxを作用させた値を取得。O(log(n))
*/
template <typename X>
struct SegTree {
    using FX = function<X(X, X)>;
    int n;
    FX fx;
    const X ex;
    vector<X> dat;
    SegTree(int n_, FX fx_, X ex_) : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    void update(int i, X x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    // the minimum element of [a,b)
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    X query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    /* debug */
    inline X operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < n; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};

ll N, M, K, Q, W, H, L, R, C;
string S;

int main() {
    cin >> N;

    using X = pair<ll, int>;
    auto fx = [](X x1, X x2) -> X {
        if (x1.first >= x2.first) {
            return x1;
        } else {
            return x2;
        }
    };
    X ex = make_pair(-INF, -1);
    SegTree<X> rmq(N, fx, ex);

    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        rmq.set(i, make_pair(a[i], i));
    }
    rmq.build();

    vector<ll> S(N + 1);
    vector<ll> b = a;
    sort(ALL(b));
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + b[i];
    }

    vector<ll> ans(N, 0);
    X now = rmq.query(0, N);
    ll tmp = 0;
    while (now.second > 0) {
        X next = rmq.query(0, now.second);
        int id = lower_bound(ALL(b), next.first) - b.begin();
        ll sum = (S[N] - S[id]) - next.first * (N - id);
        ans[now.second] += sum - tmp;
        tmp = sum;
        now = next;
    }
    ans[0] = S[N] - tmp;

    for (auto i : ans) {
        cout << i << endl;
    }

    return 0;
}
