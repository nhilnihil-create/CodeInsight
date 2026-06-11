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

/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    set(int i, T x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
    find_rightest(a,b,x): [a,b) で x以下の要素を持つ最右位置を求める。O(log(n))
    find_leftest(a,b,x): [a,b) で x以下の要素を持つ最左位置を求める。O(log(n))
*/
template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    RMQ(int n_) : n(), dat(n_ * 4, INF) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void set(int i, T x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }

    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INF;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }

    T find_rightest(int a, int b, int x) { return find_nearest_sub(a, b, x, 0, 0, n, true); }
    T find_leftest(int a, int b, int x) { return find_nearest_sub(a, b, x, 0, 0, n, false); }
    T find_nearest_sub(int a, int b, int x, int k, int l, int r, bool is_right) {
        if (dat[k] > x || r <= a || b <= l) {  // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn -1
            return -1;
        } else if (k >= n - 1) {  // 自分が葉ならその位置をreturn
            return (k - (n - 1));
        } else {
            if (is_right) {
                int vr = find_nearest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r, is_right);
                if (vr != -1) {  // 右の部分木を見て-1以外ならreturn
                    return vr;
                } else {  // 左の部分木を見て値をreturn
                    return find_nearest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2, is_right);
                }
            } else {
                int vl = find_nearest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2, is_right);
                if (vl != -1) {  // 左の部分木を見て-1以外ならreturn
                    return vl;
                } else {  // 右の部分木を見て値をreturn
                    return find_nearest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r, is_right);
                }
            }
        }
    }
    /* debug */
    inline T operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < n; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 2100100100;
const int MOD = 1e9 + 7;

ll N, M, K, Q, W, H, L, R, C;
string S;

int main() {
    ll x;
    cin >> N >> x;
    vector<ll> a(N);
    RMQ<ll> rmq(N * 2);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        rmq.update(i, a[i]);
        rmq.update(i + N, a[i]);
    }

    ll ans = 1e18;
    for (int k = 0; k < N; k++) {
        ll sum = k * x;
        for (int i = 0; i < N; i++) {
            sum += rmq.query(i + N - k, i + N + 1);
        }
        chmin(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
