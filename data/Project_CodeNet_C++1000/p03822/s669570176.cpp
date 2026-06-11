#ifndef UTIL_INCLUDED
#define UTIL_INCLUDED

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
// #define DEBUGGING

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

namespace __init {

struct InitIO {
    InitIO() {
        cin.tie(0);
        ios_base::sync_with_stdio(false);
        cout << fixed << setprecision(30);
    }
} init_io;

}

#ifndef DEBUG_FILE
#ifdef DEBUGGING
#include "../debug.cpp"
#else
#define DEBUG(...) 0
#endif
#endif

#endif

VV<ll> children;

ll calc(ll now) {
    V<ll> dv;
    for(ll c : children[now]) dv.push_back(calc(c));
    DEBUG(now, dv);
    sort(ALLR(dv));
    ll ret = 0;
    for(ll i = 0; i < dv.size(); i++) chmax(ret, dv[i] + i);
    return ret + 1;
}

int main() {
    ll N;
    cin >> N;
    children.resize(N);
    for(ll i = 1; i < N; i++) {
        ll a;
        cin >> a;
        a--;
        children[a].push_back(i);
    }
    DEBUG(children);
    cout << calc(0) - 1 << endl;
    return 0;
}
