#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>
#include <random>
#include <complex>
#include <functional>
#include <tuple>

using namespace std;

#define Rep(i,a,b) for(ll i = a; i < b; ++i)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")

using ll = long long;

constexpr int inf = 1e9 + 7;
constexpr ll infll = 1ll << 60ll;
constexpr ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

namespace {
    template<typename T> void chmax(T& a, T b) { a = std::max(a, b); }
    template<typename T> void chmin(T& a, T b) { a = std::min(a, b); }
    template<typename T> void chadd(T& a, T b) { a = a + b; }

    void Cout(long long x, const char* end = "\n") { std::cout << x << end; }
    template <typename T> void Cout(const T& x, const char* end = "\n") { std::cout << x << end; }
    template <typename T> void Cout(const std::vector<T>& x, const char* sep = " ", const char* end = "\n") { for (std::size_t i = 0, sz = x.size(); i < sz; i++) { std::cout << x[i] << (i == sz - 1 ? end : sep); } }

    // 標準入出力
    struct inp {
        std::size_t sz;
        inp(std::size_t _sz = 1) : sz(_sz) {}
        template <typename T> operator T () const { T a; std::cin >> a; return a; }
        template <typename T> operator std::vector<T>() const { std::vector<T> a(sz); for (std::size_t i = 0; i < sz; i++) std::cin >> a[i]; return a; }
    };

    // 2次元用の標準入出力
    template<typename T>
    struct inpn {
        std::size_t szi, szj;
        inpn(std::size_t _szi, std::size_t _szj) : szi(_szi), szj(_szj) {}
        operator std::vector<std::vector<T>>() const {
            std::vector<std::vector<T>> a(szi, std::vector<T>(szj));
            for (std::size_t i = 0; i < szi; ++i)
                for (std::size_t j = 0; j < szj; ++j) cin >> a[i][j];
            return a;
        }
    };

    inp inp1; // input one

        // セグメントツリーのライブラリ
    template<typename T>
    class SegmentTree {
    public:
        // _n:必要サイズ, _def:初期値かつ単位元, _operation:クエリ関数,
        // _update:更新関数
        SegmentTree(size_t _n, T _def, std::function<T(T, T)> _operation,
            std::function<T(T, T)> _update)
            : def(_def), operation(_operation), update(_update) {
            n = 1;
            while (n < _n) {
                n *= 2;
            }
            node = std::vector<T>(2 * n - 1, def);
        }

        // 場所i(0-indexed)の値をxで更新
        void change(int i, T x) {
            i += n - 1;
            node[i] = update(node[i], x);
            while (i > 0) {
                i = (i - 1) / 2;
                node[i] = operation(node[i * 2 + 1], node[i * 2 + 2]);
            }
        }

        // [a, b)の区間クエリを実行
        T query(int a, int b) {
            return _query(a, b, 0, 0, n);
        }

        // 添字でアクセス
        T operator[](int i) {
            return node[i + n - 1];
        }

        int n;                       // 葉の数
        std::vector<T> node;              // データを格納するvector
    private:
        T def;                       // 初期値かつ単位元
        std::function<T(T, T)> operation; // 区間クエリで使う処理
        std::function<T(T, T)> update;    // 点更新で使う処理

        // 区間[a,b)の総和。ノードk=[l,r)に着目している。
        T _query(int a, int b, int k, int l, int r) {
            if (r <= a || b <= l) return def; // 交差しない
            if (a <= l && r <= b)
                return node[k]; // a,l,r,bの順で完全に含まれる
            else {
                T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子
                T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子
                return operation(c1, c2);
            }
        }
    };
}

int main() {

    ll n, k;
    cin >> n >> k;
    vector<ll> a = inp(n);

    // Sum([l, r)) = Sum(r) - Sum(l) >= k * (r - l)　となればよい
    // Sum(r) - k * r >= Sum(l) -k * l となる場合の数の総和が答え
    // なので転倒数を求めればよい

    vector<ll> s(n + 1, 0LL);
    rep(i, n) s[i + 1] = s[i] + a[i];

    vector<ll> b(n + 1);
    rep(i, n + 1) {
        b[i] = s[i] - k * i;
    }

    // 使われている奴だけに圧縮する
    map<ll, int> mp;
    rep(i, n + 1) ++mp[b[i]];
    
    vector<ll> v;
    for (auto m : mp) {
        v.emplace_back(m.first);
    }

    ll ans = 0LL;

    SegmentTree<int> seg(v.size() + 1LL, 0, [](int a, int b)->int {return a + b; }, [](int a, int b)->int {return a + b; });

    // b[l] >= b[r] となればよい
    rep(i, n + 1) {
        // 自分より左側で自分以上の値の数を求める
        int index = lower_bound(allof(v), b[i]) - v.begin();
        ans += seg.query(0, index + 1);
        seg.change(index, +1);
    }

    Cout(ans);

    // O(nlogn)
    // 成長を感じる・・・ 類題解いたからだけど

    return 0;
}