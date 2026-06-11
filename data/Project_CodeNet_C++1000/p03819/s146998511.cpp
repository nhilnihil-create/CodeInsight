#include <bits/stdc++.h>
using namespace std;

#define rep_0(i, end) for(int i = 0; i < (end); ++i)
#define rep_1(i, fr, ba) for(int i = (fr); i <= (ba); ++i)
#define rep(...) overload_rep(__VA_ARGS__, rep_1, rep_0)(__VA_ARGS__)
#define overload_rep(arg_0, arg_1, arg_2, name, ...) name
#define all(box) box.begin(), box.end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class Monoid, class Effector>
struct LazySegmentTree {
private:

    int sz, height;
    vector<Monoid> node;
    vector<Effector> lazy;
    using Func_M = function<Monoid(Monoid, Monoid)>;
    using Func_E = function<Effector(Effector, Effector)>;
    using Merge = function<Monoid(Monoid, Effector, int)>;
    const Func_M operate_m;
    const Func_E operate_e;
    const Merge merge;
    const Monoid unit_m;
    const Effector unit_e;

    Monoid reflect(const int& i, const int& len) const {
        return lazy[i] == unit_e ? node[i] : merge(node[i], lazy[i], len);
    }

    void propagate(const int& i, const int& len) {
        if(lazy[i] == unit_e)return;
        if(i < sz){
            lazy[i << 1] = operate_e(lazy[i << 1], lazy[i]);
            lazy[i << 1 | 1] = operate_e(lazy[i << 1 | 1], lazy[i]);
        }
        node[i] = merge(node[i], lazy[i], len);
        lazy[i] = unit_e;
    }

public:

    LazySegmentTree() { }
    LazySegmentTree(const Monoid& m, const Effector& e, const Func_M& f1, const Func_E& f2, const Merge& f3) 
        : unit_m(m), unit_e(e), operate_m(f1), operate_e(f2), merge(f3) { }
    LazySegmentTree(const vector<Monoid>& vec, const Monoid& m, const Effector& e, const Func_M& f1, const Func_E& f2, const Merge& f3) 
        : unit_m(m), unit_e(e), operate_m(f1), operate_e(f2), merge(f3) { bulid(vec); }
    ~LazySegmentTree(){}

    void init() {
        fill(node.begin(), node.end(), unit_m);
        fill(lazy.begin(), lazy.end(), unit_e);
    }

    void bulid(const vector<Monoid>& vec) {
        for(sz = 1, height = 0; sz < (int)vec.size(); sz <<= 1, ++height);
        node.assign(sz + sz, unit_m);
        lazy.assign(sz + sz, unit_e);
        for(int i = 0; i < (int)vec.size(); ++i)
            node[i + sz] = vec[i];
        for(int i = sz - 1; i > 0; --i)
            node[i] = operate_m(node[i << 1], node[i << 1 | 1]);
    }

    void effect(const int& l, const int& r, const Effector& value) {
        int tl = l + sz, tr = r + sz - 1;
        for(int i = height; i >= 0; --i){
            propagate(tl >> i, 1 << i);
            propagate(tr >> i, 1 << i);
        }
        tl = l + sz; tr  = r + sz;
        for(int i = 1; tl < tr; tl >>= 1, tr >>= 1, i <<= 1){
            if(tl & 1)propagate(tl, i), lazy[tl] = operate_e(lazy[tl], value), propagate(tl++, i);
            if(tr & 1)propagate(--tr, i), lazy[tr] = operate_e(lazy[tr], value), propagate(tr, i);
        }
        tl = (l + sz) >> 1; tr = (r + sz - 1) >> 1;
        for(int i = 0; tl > 0; tl >>= 1, tr >>= 1, ++i){
            node[tl] = operate_m(reflect(tl << 1, 1 << i), reflect(tl << 1 | 1, 1 << i));
            node[tr] = operate_m(reflect(tr << 1, 1 << i), reflect(tr << 1 | 1, 1 << i));
        }
    }

    Monoid fold(const int& l, const int& r){
        Monoid vl = unit_m, vr = unit_m;
        int tl = l + sz, tr = r + sz - 1;
        for(int i = height; i >= 0; --i) {
            propagate(tl >> i, 1 << i);
            propagate(tr >> i, 1 << i);
        }
        tl = l + sz; tr = r + sz;
        for(int i = 1; tl < tr; tl >>= 1, tr >>= 1, i <<= 1) {
            if(tl & 1)vl = operate_m(vl, reflect(tl++, i));
            if(tr & 1)vr = operate_m(reflect(--tr, i), vr);
        }
        return operate_m(vl, vr);
    }

    Monoid operator [] (const int& i) {
        return fold(i, i + 1);
    }

    Monoid operator () (const int& l, const int& r) {
        return fold(l, r);
    }

};

int main() {

    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> Q(M);
    rep(i, N) {
        int l, r;
        cin >> l >> r;
        Q[r - l].emplace_back(l - 1, r);
    }

    const int unit = 0;
    const auto f1 = [](int i, int j) { return i + j; };
    const auto f2 = [](int i, int j, int l) { return i + j * l; };
    const vector<int> initial(M, unit);
    vector<int> ans1(M, unit);
    LazySegmentTree<int, int> sum(initial, unit, unit, f1, f1, f2);
    LazySegmentTree<int, int> ans2(initial, unit, unit, f1, f1, f2);

    rep(i, M) {
        for(int j = i; j < M; j += i + 1) {
            ans1[i] += sum[j];
        }
        for(const auto& query : Q[i]) {
            int l, r;
            tie(l, r) = query;
            ans2.effect(0, i + 1, 1);
            sum.effect(l, r, 1);
        }
    }

    rep(i, M) cout << ans1[i] + ans2[i] << '\n';
    return 0;

}
