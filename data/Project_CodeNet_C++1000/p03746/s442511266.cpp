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

int n, m;
vector<int> g[N];
bool used[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int x = 1, y = 1;
    used[1] = 1;
    vector<int> right;
    vector<int> left;
    while (1) {
        int A = -1;
        for (int to : g[y]) {
            if (!used[to]) {
                A = to;
                break;
            }
        }
        if (A == -1) break;
        used[A] = 1;
        y = A;
        right.emplace_back(y);
    }
    while (1) {
        int A = -1;
        for (int to : g[x]) {
            if (!used[to]) {
                A = to;
                break;
            }
        }
        if (A == -1) break;
        used[A] = 1;
        x = A;
        left.emplace_back(x);
    }
    reverse(all(left));
    cout << left.size() + 1 + right.size() << endl;
    for (int I : left) {
        cout << I << " ";
    }
    cout << 1 <<  " ";
    for (int i : right) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
 
/*



3
0 1
-2 3
2 2

3
0 1
-2 2
2 2

*/