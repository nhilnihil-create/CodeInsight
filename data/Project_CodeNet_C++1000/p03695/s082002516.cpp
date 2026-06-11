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
//#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int tourist = 0;
    map<int, int> m;
    rep(i, n) {
        cin >> a[i];
        if (a[i] >= 3200)
            tourist++;
        else
            m[a[i] / 400]++;
    }
    int min1 = m.size();
    int max1 = m.size();
    if (tourist == n) {
        cout << 1 << ' ' << n << endl;
        return 0;
    }
    if (tourist) {
        max1 += tourist;
    }
    cout << min1 << ' ' << max1 << endl;
}