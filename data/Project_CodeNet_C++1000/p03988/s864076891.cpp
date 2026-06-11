#include <bits/stdc++.h>
using namespace std;
//#define DEBUG_MODE
#define endl '\n'
#ifdef DEBUG_MODE
#define DEBUG(...) debug_func_mult(split_names(#__VA_ARGS__), __VA_ARGS__)
#define DEBUG_ENDL endl << flush
#define DEBUG_SEPARATOR_LINE cout<<"=================\n"
#else
#define DEBUG(...) 0
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

template <typename T>
void debug_func_mult(int idx, const V<string> &names, const T &t) {
    debug_func(t, names[idx]);
}

template <typename T>
void debug_func_mult(const V<string> &names, const T &t) {
    debug_func(t, names[0]);
}

template <typename Head, typename... Tail>
void debug_func_mult(int idx, const V<string> &names, const Head &head, const Tail&... args) {
    debug_func(head, names[idx]);
    debug_func_mult(idx + 1, names, args...);
}

template <typename Head, typename... Tail>
void debug_func_mult(const V<string> &names, const Head &head, const Tail&... args) {
    debug_func(head, names[0]);
    debug_func_mult(1, names, args...);
}

V<string> split_names(string &&s) {
    replace(ALL(s), ' ', ',');
    V<string> ret;
    istringstream ss(s);
    string t;
    while(getline(ss, t, ',')) if(t.size()) ret.push_back(move(t));
    return move(ret);
}

void init_io() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(30);
}

ll H, W;

void str_and(const V<string> &red, const V<string> &blue) {
#ifdef DEBUG_MODE
    V<string> output(H, string(W, '.'));
    for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++) if(red[i][j] == '#' && blue[i][j] == '#') output[i][j] = '#';
    cout << endl;
    for(const auto &s : output) cout << s << endl;
#endif
}

int main() {
    ll N;
    cin >> N;
    V<ll> A(N);
    V<ll> cnt(N + 10, 0);
    for(ll &e : A) {
        cin >> e;
        cnt[e]++;
    }
    ll max_len = *max_element(ALL(A));
    bool poss = true;
    if(max_len & 1) {
        ll center = (max_len + 1) / 2;
        if(cnt[center] != 2) poss = false;
        for(ll i = center + 1; i <= max_len; i++) if(cnt[i] < 2) poss = false;
    } else {
        ll center = max_len / 2;
        if(cnt[center] != 1) poss = false;
        for(ll i = center + 1; i <= max_len; i++) if(cnt[i] < 2) poss = false;
    }
    cout << (poss ? "Possible" : "Impossible") << endl;
    return 0;
}
