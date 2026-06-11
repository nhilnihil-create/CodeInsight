#include <bits/stdc++.h>
using namespace std;
//#define DEBUG_MODE
#define endl '\n'
#ifdef DEBUG_MODE
#define DEBUG(X) debug_func(X, #X)
#define DEBUG_ENDL endl << flush
#define DEBUG_SEPARATOR_LINE cout<<"=================\n"
#else
#define DEBUG(X) 0
#define DEBUG_ENDL 0
#define DEBUG_SEPARATOR_LINE 0
#endif
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
#define DEBUG_ENDL_S(S) ((S).size() ? "\n" : "") << flush;
template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
template <typename T, typename U> using P = pair<T, U>;
using ll = int64_t;
using PLL = P<ll, ll>;
template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename Head, typename... Tail> const Head& var_min(const Head &head, const Tail&... tail) { return min(head, var_min(tail...)); }
template <typename Head, typename... Tail> const Head& var_max(const Head &head, const Tail&... tail) { return max(head, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }
void debug_func_preffix(const string &s) { if(s.size()) cout << s << " = "; }
template <typename T>
void debug_func(const T &t, const string &s = "") {
    debug_func_preffix(s);
    cout << t << DEBUG_ENDL_S(s);
}
template <typename T, typename U>
void debug_func(const P<T, U> &p, const string &s = "") {
    debug_func_preffix(s);
    cout << "(";
    debug_func(p.first);
    cout << ", ";
    debug_func(p.second);
    cout << ")" << DEBUG_ENDL_S(s);
}
template <typename T>
void debug_func(const V<T> &v, const string &s = "") {
    for(ll i = 0; i < v.size(); i++) {
        string t = s + "[" + to_string(i) + "]";
        debug_func(v[i], t);
    }
}

void init_io() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(30);
}

template <typename T, typename L>
class LazySegmentTree{
private:
    ll N;
    T init_node;
    L init_lazy;
    vector<T> node;
    vector<L> lazy;
    vector<bool> lazy_flag;
    function<T (T, T)> merge_node;
    function<T (T, L)> apply_lazy_value;
    function<L (L, L)> update_lazy_value;
    function<L (ll, ll, L)> create_lazy_value;
    
public:
    LazySegmentTree(const vector<T> &v, 
                    const T &init_node,
                    const L &init_lazy, 
                    const decltype(merge_node)        &merge_node,
                    const decltype(apply_lazy_value)  &apply_lazy_value,
                    const decltype(update_lazy_value) &update_lazy_value,
                    const decltype(create_lazy_value) &create_lazy_value) 
        : init_node(init_node),
          init_lazy(init_lazy),
          merge_node(merge_node),
          apply_lazy_value(apply_lazy_value),
          update_lazy_value(update_lazy_value),
          create_lazy_value(create_lazy_value)
    {
        ll tmp = 1;
        while(tmp < v.size()) tmp *= 2;
        N = tmp;
        node.resize(2 * N - 1, init_node);
        lazy.resize(2 * N - 1, init_lazy);
        lazy_flag.resize(2 * N - 1, false);
        for(ll i = 0; i < v.size(); i++) {
            node[i + N - 1] = v[i];
        }
        for(ll i = N - 2; 0 <= i; i--) {
            node[i] = merge_node(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    /*
     * node[pos] -> [left, right)
     */
    void lazy_eval(ll pos, ll left, ll right) {
        if(!lazy_flag[pos]) {
            return;
        }

        node[pos] = apply_lazy_value(node[pos], lazy[pos]);
        lazy_flag[pos] = false;

        /* 
         * whether the node is the bottom of tree or not.
         */
        if(right - left > 1) {
            for(ll idx : {2 * pos + 1, 2 * pos + 2}) {
                lazy[idx] = update_lazy_value(lazy[idx], lazy[pos]);
                lazy_flag[idx] = true;
            }
        }

        lazy[pos] = init_lazy;
    }

    /*
     * If you want to call this func from out of class, in many cases you don't have to change the args pos, node_left, node_right.
     * Be careful that the range is half-open interval.
     * [left, right), [node_left, node_right)
     * @param left:         lower limit of interval of query
     * @param right:        upper limit of interval of query
     * @param val:          the value gave from query
     * @param node_left:    lower limit of interval of the node points.
     * @param node_right:   upper limit of interval of the node points.
     */
    void update_query(ll left, ll right, ll val, ll pos = 0, ll node_left = 0, ll node_right = -1) {
        if(node_right < 0) {
            node_right = N;
        }

        /*
         * Execute lazy evaluation.
         */
        lazy_eval(pos, node_left, node_right);

        /*
         * If the node is out of inrerval, return.
         */
        if(right <= node_left || node_right <= left) {
            return;
        }


        /*
         * If the node cover the interval complety, update this->lazy and execute lazy_eval.
         * Else recursion.
         */
        if(left <= node_left && node_right <= right) {
            lazy[pos] = create_lazy_value(node_left, node_right, val);
            lazy_flag[pos] = true;
            lazy_eval(pos, node_left, node_right);
        }else{

            /*
             * recursion
             */
            update_query(left, right, val, 2 * pos + 1, node_left, (node_left + node_right) / 2);
            update_query(left, right, val, 2 * pos + 2, (node_left + node_right) / 2, node_right);

            node[pos] = merge_node(node[2 * pos + 1], node[2 * pos + 2]);
        }
    }

    T get_query(ll left, ll right, ll pos = 0, ll node_left = 0, ll node_right = -1) {
        if(node_right < 0) {
            node_right = N;
        }

        /*
         * Evaluate the node[pos]
         */
        lazy_eval(pos, node_left, node_right);

        if(node_right <= left || right <= node_left) {
            return init_node;
        }
        if(left <= node_left && node_right <= right) {
            return node[pos];
        }

        ll split = (node_left + node_right) / 2;
        return merge_node(get_query(left, right, 2 * pos + 1, node_left, split),
                          get_query(left, right, 2 * pos + 2, split, node_right));
    }
};

int main() {
    init_io();
    ll N, M;
    cin >> N >> M;
    
    VV<PLL> ranges(M + 10);
    LazySegmentTree<ll, ll> lst(V<ll>(M + 10, 0), 0, 0,
                                [](ll a, ll b) { return a + b; },
                                [](ll a, ll b) { return a + b; },
                                [](ll a, ll b) { return a + b; },
                                [](ll l, ll r, ll v) { return v; });
    ll sum_ok = N;
    for(ll i = 0; i < N; i++) {
        ll l, r;
        cin >> l >> r;
        ranges[r - l + 1].emplace_back(l, r);
    }
    cout << N << endl;
    for(ll d = 2; d <= M; d++) {
        for(const auto &p : ranges[d - 1]) {
            ll l, r;
            tie(l, r) = p;
            lst.update_query(l, r + 1, 1);
            sum_ok--;
        }
        ll cnt = 0;
        for(ll i = 1; i * d <= M; i++) cnt += lst.get_query(i * d, i * d + 1);
        cout << sum_ok + cnt << endl;
    }
    return 0;
}
