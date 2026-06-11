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

vector<int> f(LL n, int& mx) {
    if (n == 1) {
        mx = 0; return {};
    }
    int t; vector<int> prev;
    if (n % 2 == 0) {
        prev = f(n / 2, t);
        prev.push_back(mx = t + 1);
    } else {
        prev = f(n - 1, t);
        prev.insert(prev.begin(), mx = t + 1);
    }
    dbg(prev);
    return prev;
}

int main() {
    LL n; int M; cin >> n;
    vector<int> a = f(++n, M);
    printf("%d\n", 2 * M);
    FOR (i, 0, M) printf("%d ", a[i]);
    FOR (i, 1, M + 1) printf("%d%c", i, i == _i - 1 ? '\n' : ' ');
}
