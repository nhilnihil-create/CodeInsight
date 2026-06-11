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

vector<int> g[N];
int color[N];
bool bip = 1;
int sz = 0;

void dfs(int v, int col = 1) {
    color[v] = col;
    ++sz;
    for (int to : g[v]) {
        if (!color[to]) {
            dfs(to, 3 - col);
        }
        if (color[to] == color[v]) {
            bip = 0;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    int one = 0, two = 0;
    int isol = 0;
    for (int i = 1; i <= n; ++i) {
        if (!color[i]) {
            bip = 1;
            sz = 0;
            dfs(i);
            if (sz == 1) {
                ++isol;
            } else {
                if (bip) {
                    ++two;
                } else {
                    ++one;
                }
            }
        }
    }
    cout << one * one + (one + two) * two * 2 + isol * (n - isol) * 2 + isol * isol << '\n';
    return 0;
}
