#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <random>
#include <iomanip>
#include <bitset>
 
 
using namespace std;
 
template<typename T> void uin(T &a, T b) {
    if (b < a) {
        a = b;
    }
}
 
template<typename T> void uax(T &a, T b) {
    if (b > a) {
        a = b;
    }
}
#define int long long
#define left left228
#define right right228
#define prev prev228
#define mp make_pair
#define all(v) v.begin(), v.end()
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define x first
#define y second

const int N = 100 * 1000 + 228;

int n, k;
vector<int> g[N];
int a[N], max_deep[N];
int res = 0;

void dfs(int v, int par) {
    max_deep[v] = 0;
    for (int to : g[v]) {
        if (to == par) continue;
        dfs(to, v);
        max_deep[v] = max(max_deep[v], max_deep[to] + 1);
    }
    if (max_deep[v] == k - 1 && par != 1) {
        ++res;
        max_deep[v] = -1;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (a[1] != 1) {
        ++res;
        a[1] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        g[a[i]].push_back(i);
    }
    for (int sons : g[1]) {
        dfs(sons, 1);
    }
    cout << res << '\n';
    return 0;
}