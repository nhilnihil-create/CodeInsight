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

const int N = 200 * 1000 + 228;
const int INF = 3e9 + 228;

int n, l, t;
int x[N], w[N], fx[N], meet[N], pref[N][3], ans[N];

int dist(int i) {
    return x[(i - 1) % n + 1] + l * ((i - 1) / n);
}
int summa(int i, int T) {
    return (pref[(i - 1) % n + 1][T] + ((i - 1) / n) * pref[n][T]) % n;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> w[i];
        if (w[i] == 1) {
            fx[i] = (x[i] + t) % l;
        } else {
            fx[i] = ((x[i] - t) % l + l) % l;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 2; ++j) {
            pref[i][j] = pref[i - 1][j] + (w[i] == j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (w[i] == 1) {
            int l = i, r = INF;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (dist(m) - dist(i) < t * 2) l = m;
                else r = m;
            }
            meet[i] = summa(l, 2) - summa(i, 2);
            ans[(i - 1 + meet[i]) % n + 1] = fx[i];
        } else {
            int l = 1, r = i + n * INF;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (dist(i + n * INF) - dist(m) < t * 2) r = m;
                else l = m;
            }
            meet[i] = summa(i + n * INF, 1) - summa(r - 1, 1);
            ans[((i - 1 - meet[i]) % n + n) % n + 1] = fx[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << '\n';
    }
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