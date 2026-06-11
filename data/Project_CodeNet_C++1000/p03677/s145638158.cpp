#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (n); ++i)
const int INF  = 1   << 30;
const  ll INFF = 1LL << 60;

/*
    入力例1において, 1 -> 5を改善したいとき, xは[3, 5]である必要がある.
    x = 1のとき : 4 -> 0回改善
    x = 2のとき : 4 -> 0回改善
    x = 3のとき : 3 -> 1回改善
    x = 4のとき : 2 -> 2回改善
    x = 5のとき : 1 -> 3回改善
    x = 6のとき : 4 -> 0回改善
    このように, 各a_i -> a_(i+1)において, xにしたときにどれだけ改善するかを求めればよい
        -> 連番をどのように構成すればいいか
            -> (想定解じゃなさそうだけど)2回の累積和 + 区間addmaxの遅延セグ木で実現できそう
    ex.) [2, 4]に連番を入れる
    (1) a[2] += 1, a[4 + 1] -= 1として累積和をとると,
        [0, 0, 1, 1, 1, 0, 0] (単純なimos)
    (2) もう一回累積和をとると,
        [0, 0, 1, 2, 3, 3, 3]
    (3) 最後に遅延セグ木で, 5以降に-3する.
        [0, 0, 1, 2, 3, 0, 0]
    このようにしてできた配列のmaxを, お気に入りなしの手数から引けば答え!
    (※) resは最大N * Mぐらいになるので, intに入らないです(1WA)
*/

template <typename Monoid, typename OperatorMonoid = Monoid> struct LazySegmentTree {

  typedef function< Monoid(Monoid, Monoid) > F;
  typedef function< Monoid(Monoid, OperatorMonoid) > G;
  typedef function< OperatorMonoid(OperatorMonoid, OperatorMonoid) > H;
  typedef function< OperatorMonoid(OperatorMonoid, int) > P;

  int sz;
  F f;
  G g;
  H h;
  P p;
  Monoid d1;
  OperatorMonoid d0;
  vector< Monoid > dat;
  vector< OperatorMonoid > laz;

  LazySegmentTree(int n, F f, G g, H h, Monoid d1, OperatorMonoid d0,
              vector< Monoid > v = vector< Monoid >(), P p = [] (OperatorMonoid a, int b) { return a; })
              : f(f), g(g), h(h), d1(d1), d0(d0), p(p) {
    sz = 1; while (sz < n) sz <<= 1;
    dat.assign(2 * sz - 1, d1);
    laz.assign(2 * sz - 1, d0);
    if (n == (int)v.size()) build(n, v);
  }

  void build(int n, vector<Monoid> &v) {
    for (int i = 0; i < n; i++)
      dat[i + sz - 1] = v[i];
    for (int i = sz - 2; i >= 0; i--)
      dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
  }

  inline void eval(int len, int k) {
    if (laz[k] == d0) return;
    if (k * 2 + 1 < sz * 2 - 1) {
      laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);
      laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);
    }
    dat[k] = g(dat[k], p(laz[k], len));
    laz[k] = d0;
  }

  Monoid update(int a, int b, OperatorMonoid x, int k, int l, int r) {
    eval(r - l, k);
    if(r <= a || b <= l) return dat[k];
    if(a <= l && r <= b) {
      laz[k] = h(laz[k], x);
      return g(dat[k], p(laz[k], r - l));
    }
    return dat[k] = f(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
            update(a, b, x, k * 2 + 2, (l + r) / 2, r));
  }

  Monoid update(int a, int b, OperatorMonoid x) {
    return update(a, b, x, 0, 0, sz);
  }

  Monoid query(int a, int b, int k, int l, int r) {
    eval(r - l, k);
    if (r <= a || b <= l) return d1;
    if (a <= l && r <= b) return dat[k];
    Monoid vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    Monoid vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return f(vl, vr);
  }

  Monoid query(int a, int b) {
    return query(a, b, 0, 0, sz);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }

};

int N, M;
vector<int> A;

int main() {

    cin >> N >> M;

    A.resize(N);
    REP(i, N) {
        cin >> A[i];
        --A[i];     // 0-indexed
    }

    ll res = 0;

    // 5 -> 1のように最初に戻る場合を考慮して2倍の長さに
    vector<ll> acc(2 * M, 0);

    // 遅延セグ木で引くやつ ({idx, num})
    vector<pair<int, int>> sub;

    REP(i, N - 1) {
        int p = A[i], q = A[i + 1];
        if (p > q) q += M;
        res += q - p;
        // 改善できない場合はスキップ
        if (p + 2 > q) continue;
        // [p + 2, q]に連番を入れる!
        acc[p + 2]++, acc[q + 1]--;
        sub.emplace_back(make_pair(q + 1, (q + 1) - (p + 2)));
    }

    // 2回累積和をとる
    REP(i, 2) REP(j, 2 * M - 1) acc[j + 1] += acc[j];
    // 2倍でとったものを圧縮
    REP(i, M) acc[i] += acc[i + M];
    
    // セグ木初期化用
    vector<ll> init(M, 0);
    REP(i, M) init[i] = acc[i];

    // 区間addmax
    LazySegmentTree<ll> seg(M, [](ll a, ll b) {
        return max(a,b);
    }, plus<ll>(), plus<ll>(), -INFF, 0, init);

    for (auto& p: sub) {
        int idx, num;
        tie(idx, num) = p;

        /*
            idx < Mのときは, 先ほど2倍にして構築したことを考慮する.
            ex.) M = 3, [0, 1]に連番を入れたとき
                2回累積和をとって, [  1,  2,  2,  2,  2,  2]にして, subに{2, 2}をpushする.
                あとでセグ木で,       0,  0, -2, -2, -2, -2 をする.
                これを圧縮すると,  [  3,  4,  4]
                                   0,  0, -2
                                  -2, -2, -2 <- これを考慮!
         */
        if (idx < M) seg.update(0, M, -num);

        seg.update(idx % M, M, -num);
    }

    cout << res - seg.query(0, M) << endl;

}