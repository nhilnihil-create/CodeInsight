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
    string a, b, c;
    cin >> a >> b >> c;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    char s = a.back();
    a.pop_back();
    while (true) {
        if (s == 'a') {
            if (a.empty()) {
                cout << "A" << endl;
                return 0;
            }
            else {
                s = a.back();
                a.pop_back();
            }
        }
        else if (s == 'b') {
            if (b.empty()) {
                cout << "B" << endl;
                return 0;
            }
            else {
                s = b.back();
                b.pop_back();
            }
        }
        else if (s == 'c') {
            if (c.empty()) {
                cout << "C" << endl;
                return 0;
            }
            else {
                s = c.back();
                c.pop_back();
            }
        }
    }
}