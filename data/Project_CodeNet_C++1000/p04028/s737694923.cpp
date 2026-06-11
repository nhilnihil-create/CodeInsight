#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()

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

void init_io() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(30);
}

// #define DEBUGGING
#ifdef DEBUGGING
#include "../debug.cpp"
#else
#define DEBUG(...) 0
#endif

const ll MOD = 1e9 + 7;

int main() {
    init_io();
    ll N;
    cin >> N;
    string S;
    cin >> S;
    V<ll> dp(5010, 0);
    dp[0] = 1;
    for(ll i = 0; i < N; i++) {
        V<ll> ndp(5010, 0);
        for(ll pre_len = 0; pre_len <= N; pre_len++) {
            (ndp[pre_len + 1] += dp[pre_len]) %= MOD;
            if(pre_len == 0) (ndp[0] += dp[0]) %= MOD;
            else (ndp[pre_len - 1] += dp[pre_len] * 2 % MOD) %= MOD;
        }
        dp = move(ndp);
    }
    cout << dp[S.size()] << endl;
    return 0;
}
