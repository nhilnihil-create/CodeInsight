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
#define list list228
#define mp make_pair
#define all(v) v.begin(), v.end()
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define x first
#define y second

const int N = 100 * 1000 + 228;

int a[N], up[N];
vector<int> g[N];

void dfs(int v, int par = -1) {
    int S = 0;
    vector<int> sons;
    for (int to : g[v]) {
        if (to == par) continue;
        sons.push_back(to);
        dfs(to, v);
        S += up[to];
    }
    if (sons.empty()) {
        up[v] = a[v];
        return;
    }
    sort(sons.begin(), sons.end(), [&] (int i, int j) {
        return up[i] < up[j];
    });
    if ((int)sons.size() == 1) {
        if (up[sons[0]] != a[v]) {
            // ya che-to seychas voobshe ne ponyal
            cout << "NO\n";
            exit(0);
        }
        up[v] = up[sons[0]];
    } else {
        if (a[v] > S || 2 * a[v] - S < 0) {
            cout << "NO\n";
            exit(0);
        }
        up[v] = 2 * a[v] - S;
        int new_S = S - up[v];
        int all = 0;
        for (int son : sons) {
            all += max(0LL, up[son] - new_S / 2);
        }
        if (all > up[v]) {
            cout << "NO\n";
            exit(0);
        }
    }
}

int deg[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        ++deg[u], ++deg[v];
        g[u].push_back(v); g[v].push_back(u);
    }
    if (n == 2) {
        if (a[1] == a[2]) {
            cout << "YES\n";
        } else cout << "NO\n";
        return 0;
    }
    int root = 1;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > deg[root]) {
            root = i;
        }
    }
    dfs(root);

    // cout << "root=" << root << endl;
    // for (int i = 1; i <= n; ++i) {
    //     cout << "up[" << i << "]=" << up[i] << endl;
    // }
    if (up[root] == 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}