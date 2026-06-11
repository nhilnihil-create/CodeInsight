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

string to_string(const string &s) { return s; }

template <typename T, typename U>
string to_string(const P<T, U> &p) {
    string ret = "(";
    ret += to_string(p.first);
    ret += ", ";
    ret += to_string(p.second);
    ret += ")";
    return move(ret);
}

template <typename T>
string to_string(const V<T> &v) {
    string ret = "{";
    for(const T &t : v) {
        ret += to_string(t);
        ret += ", ";
    }
    ret += "}";
    return move(ret);
}

template <typename T>
void debug_func(const T &t, const string &s = "") {
    if(s.size()) cout << s << " = ";
    cout << to_string(t) << DEBUG_ENDL_S(s);
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

const ll maxv = 1e9;

int main() {
    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    if(h == 1 && w == 1) {
        cout << "No\n";
        return 0;
    }
    ll cnt = (H / h) * (W / w);
    ll val = (maxv - 1) / (h * w - 1);
    ll minusv = val * (h * w - 1) + 1;
    ll rest = H * W - cnt * h * w;
    if(cnt >= rest * val) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for(ll i = 1; i <= H; i++) {
        for(ll j = 1; j <= W; j++) {
            cout << (i % h == 0 && j % w == 0 ? -minusv : val);
            cout << " \n"[j == W];
        }
    }
    return 0;
}
