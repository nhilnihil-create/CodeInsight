#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

// Segment Tree {{{
template <typename T>
class SegTree {
 private:
    int _n;
    T _init_val;
    std::vector<T> _data;
    std::function<T(T, T)> _f;

    T _query(int a, int b, int k, int l, int r) {
        // [a b)と[l r]が交差しない
        if (r <= a || b <= l) return _init_val;

        // [a b)が[l r]を含む
        if (a <= l && r <= b) return _data[k];

        T vl = _query(a, b, k*2+1, l, (l+r)/2);
        T vr = _query(a, b, k*2+2, (l+r)/2, r);

        return _f(vl, vr);
    }

 public:
    SegTree(int n, T init_val, std::function<T(T, T)> f) {
        _init_val = init_val;
        _n = 1;
        _f = f;

        while (_n < n)
            _n *= 2;
        _data.resize(2 * _n, init_val);
    }

    T get(int k) {
        return _data[k + _n - 1];
    }

    void update(int k, T a) {
        k += _n-1;
        _data[k] = a;
        while (k > 0) {
            k = (k-1)/2;
            _data[k] = _f(_data[k*2+1], _data[k*2+2]);
        }
    }

    // [a b)の範囲でfを適用
    T query(int a, int b) {
        return _query(a, b, 0, 0, _n);
    }

    // 先頭からチェックし，はじめてxを満たしたインデックス
    int lower_bound(T x) {
        return _lower_bound(x, 0);
    }

    int _lower_bound(T x, int k) {
        if (k >= _n-1) {
            return k - (_n - 1);  // 葉
        } else if (_data[k] < x) {
            return _n;  // 該当なし
        } else if (x <= _data[k * 2 + 1]) {
            return _lower_bound(x, k * 2 + 1);
        } else {
            return _lower_bound(x - _data[k * 2 + 1] , k * 2 + 2);
        }
    }
};
// }}}

signed main() {
  // そのままの数列での累積和
  SegTree<ll> st1(200000,  0, [](const ll &x, const ll &y) { return x+y; });
  // 正数を取り出した数列における累積和
  SegTree<ll> st2(200000,  0, [](const ll &x, const ll &y) { return x+y; });

  ll N, K;
  cin >> N >> K;
  rep(i, N) {
    ll a;
    cin >> a;
    st1.update(i, a);
    st2.update(i, max(a, (ll)0));
  }

  ll ans = 0;
  for (ll i=0; i<=N-K; i++) {
    ll l = st2.query(0, i);
    ll m = st1.query(i,i+K);
    ll r = st2.query(i+K, N);

    // [i i+K) を黒くした場合
    ans = max(ans, l+m+r);

    // [i i+K) を白くした場合
    ans = max(ans, l+r);
  }
  cout << ans << endl;
}
