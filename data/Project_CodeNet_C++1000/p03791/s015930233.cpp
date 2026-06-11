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

const ll MOD = 1e9 + 7;

int main() {
    init_io();
    ll N;
    cin >> N;
    V<ll> A(N + 1, 0);
    for(ll i = 1; i <= N; i++) cin >> A[i];
    ll cnt = 0;
    ll space = 0, frog = 0;
    ll ans = 1;
    for(ll i = 1; i <= N; i++) {
        frog++;
        space += A[i] - A[i - 1] - 1;
        DEBUG(frog);
        DEBUG(space);
        if(i < N && frog == space + 2) {
            cnt++;
            (ans *= frog) %= MOD;
            frog--;
            space++;
        }
    }
    DEBUG(cnt);
    for(ll i = 1; i <= N - cnt; i++) (ans *= i) %= MOD;
    cout << ans << endl;
#ifdef DEBUG_MODE
    {
        ll po = 3;
        for(ll i = 1; i <= 11; i++) (po *= i) %= MOD;
        cout << po << endl;
    }
#endif
    return 0;
}
