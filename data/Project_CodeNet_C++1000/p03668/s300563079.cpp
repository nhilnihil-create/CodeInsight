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
vector<int> G[N];

int go(int u, int fa) {
    int ret = 0;
    for (int v: G[u]) {
        if (v == fa) continue;
        ret ^= go(v, u) + 1;
    }
    return ret;
}

int main() {
    int n; cin >> n;
    FOR (i, 0, n - 1) {
        int u, v; cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    puts(go(1, 0) ? "Alice" : "Bob");
}