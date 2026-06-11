#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
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

template <class T>
map<T, T> prime_factorize(T n) {
    map<T, T> res;
    for (T i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1)
        res[n] = 1;
    return res;
}

namespace my {
void merge(std::map<int, int> &a, std::map<int, int> b) {
    for (auto i = b.begin(); i != b.end(); i++) {
        if (a[i->first] > 0)
            a[i->first] += i->second;
        else
            a[i->first] = i->second;
    }
}
} // namespace my

signed main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    rep(i, ty - sy) cout << 'U';
    rep(i, tx - sx) cout << 'R';
    rep(i, ty - sy) cout << 'D';
    rep(i, tx - sx) cout << 'L';
    cout << 'L';
    rep(i, ty - sy + 1) cout << 'U';
    rep(i, tx - sx + 1) cout << 'R';
    cout << 'D';
    cout << 'R';
    rep(i, ty - sy + 1) cout << 'D';
    rep(i, tx - sx + 1) cout << 'L';
    cout << 'U' << endl;
}