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
    int n, a;
    cin >> n;
    map<int, int> m;
    rep(i, n) {
        cin >> a;
        if (a % 4 == 0)
            m[4]++;
        else if (a % 2 == 0)
            m[2]++;
        else
            m[1]++;
    }
    if (m[2] % 2 == 0) {
        if (m[4] >= m[1] - 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else {
        if (m[4] - 1 >= m[1] - 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}