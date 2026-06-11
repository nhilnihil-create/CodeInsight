#include <algorithm>
#include <bitset>
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

int f(int n) {
    if (n == 0)
        return 1;
    else
        return 2 * f(n - 1);
}

int comb(int n, int r) {
    if (r > n - r)
        r = n - r;
    int q = r;
    int up = 1;
    int down = 1;
    rep(i, q) {
        up *= n;
        down *= r;
        n--;
        r--;
    }
    return up / down;
}

signed main() {
    int n, p;
    cin >> n >> p;
    int a;
    int odd = 0;
    int even = 0;
    rep(i, n) {
        cin >> a;
        if (a % 2)
            odd++;
        else
            even++;
    }
    if (p) {
        int oddint = 0;
        repk(i, 1, odd + 1) {
            if (i % 2) {
                oddint += comb(odd, i);
            }
        }
        cout << f(even) * oddint << endl;
    }
    else {
        int oddint = 0;
        repk(i, 1, odd + 1) {
            if (i % 2 == 0) {
                oddint += comb(odd, i);
            }
        }
        cout << f(even) * (oddint + 1) << endl;
    }
}