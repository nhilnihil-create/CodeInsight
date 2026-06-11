#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF 1e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

using namespace std;
//#inculude <bits/stdc++.h>
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<int> c(m);
    vector<int> d(m);
    rep(i, m) cin >> c[i] >> d[i];
    rep(i, n) {
        int ans = 0;
        int dis = 1000000000000000;
        rep(j, m) {
            if (chmin(dis, abs(a[i] - c[j]) + abs(b[i] - d[j])))
                ans = j;
        }
        cout << ans + 1 << endl;
    }
}