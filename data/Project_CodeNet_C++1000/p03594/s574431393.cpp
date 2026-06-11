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

ll H, W, D;
V<string> ans;

void set_color(ll h, ll left, ll right, char c) {
    if(!(0 <= h && h < H)) return;
    for(ll w = left; w < right; w++) {
        if(!(0 <= w && w < W)) continue;
        ans[h][w] = c;
    }
}

void solve() {
    cin >> H >> W >> D;
    ans = V<string>(H, string(W, '.'));
    
    VV<char> color = {
        { 'R', 'Y' },
        { 'G', 'B' },
        { 'Y', 'R' },
        { 'B', 'G' },
    };

    if(D & 1) {
        string s = "RYGB";
        for(ll i = 0; i < H; i++) for(ll j = 0; j < W; j++) ans[i][j] = s[(j - i + 4444444444ll) % 4];
        return;
    }
    
    ll cidx = 0;
    for(ll uh = -(!(D & 1)); uh < H + D; uh += D / 2) {
        ll dh = uh;
        for(ll delh = 0; delh < D / 2; delh++) {
            ll len = D - 2 * delh;
            ll ccidx = 0;
            ll left = delh;
            if(cidx % 4 % 2 == 0) left -= D / 2;
            for(; left < W; left += D) {
                char col = color[cidx % 4][ccidx % 2];
                ccidx++;
                ll right = left + len;
                for(ll j = left; j < right; j++) {
                    set_color(uh - delh, left, right, col);
                    set_color(dh + delh, left, right, col);
                }
            }
        }
        cidx++;
    }
}

inline void debug() {
#ifdef DEBUG_MODE
    for(auto &s : ans) for(char &c : s) if(c != 'R') c = '.';
#endif
}

int main() {
    init_io();
    solve();
    debug();
    for(const auto &s : ans) cout << s << endl;
    return 0;
}
