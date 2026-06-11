#include <bits/stdc++.h>
using namespace std;
#define DEBUG_MODE
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

ll N;
string S;

bool check(ll idx, const V<char> &lis) {
    ll pre = (idx - 1 + N) % N;
    ll nxt = (idx + 1) % N;
    return lis[idx] == 'S' ? (S[idx] == 'o' ? lis[pre] == lis[nxt] : lis[pre] != lis[nxt])
                           : (S[idx] == 'o' ? lis[pre] != lis[nxt] : lis[pre] == lis[nxt]);
}

bool check_list(ll idx, V<char> &result) {
    if(idx == N) return check(N - 1, result) && check(0, result);
    result[idx] = 'S';
    if(check(idx - 1, result)) {
        return check_list(idx + 1, result);
    } else {
        result[idx] = 'W';
        return check_list(idx + 1, result);
    }
}

int main() {
    init_io();
    cin >> N >> S;
    for(ll i = 0; i <= 1; i++) {
        for(ll j = 0; j <= 1; j++) {
            V<char> result(N);
            result[0] = (i == 0 ? 'S' : 'W');
            result[1] = (j == 0 ? 'S' : 'W');
            if(check_list(2, result)) {
                for(char c : result) cout << c;
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
