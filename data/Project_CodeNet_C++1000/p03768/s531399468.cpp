#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifdef zerol
#define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
// -----------------------------------------------------------------------------

const int N = 1E5 + 100;
const int M = 12;
vector<int> G[N];
pair<int, int> dp[N][M];

int main() {
    int n, m, q; cin >> n >> m;
    FOR (_, 0, m) {
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cin >> q;
    FOR (ti, 1, q + 1) {
        int v, d, c; cin >> v >> d >> c;
        dp[v][d] = {ti, c};
    }
    FORD (d, 10, -1) {
        FOR (u, 1, n + 1) {
            for (int v: G[u]) {
                if (dp[v][d + 1].second)
                    dp[u][d] = max(dp[u][d], dp[v][d + 1]);
            }
        }
    }
    FOR (i, 1, n + 1) {
        pair<int, int> ans = {0, 0};
        FOR (d, 0, 11)
            ans = max(ans, dp[i][d]);
        cout << ans.second << endl;
    }
}