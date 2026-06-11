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

const int N = 2003;
const int INF = 1e18 + 228;

int a[N];
int mn[N][N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        mn[i][0] = a[i];
        for (int k = 1; k <= n; ++k) {
            mn[i][k] = min(mn[i][k - 1], a[(i + k - 1) % n + 1]);
        }
    }
    int res = INF;
    for (int cnt = 0; cnt < n; ++cnt) {
        int cur = x * cnt;
        for (int i = 1; i <= n; ++i) {
            cur += mn[i][cnt];
        }
        uin(res, cur);
    }
    cout << res << '\n';
    return 0;
}