#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

int main() {
    INIT;
    ll x, y;
    cin >> x >> y;

    if (abs(x) < abs(y)) {
        if (x > 0 && y > 0) {
            cout << y - x << endl;
        } else if (x > 0 && y < 0) {
            cout << abs(y) - abs(x) + 1 << endl;
        } else if (x < 0 && y > 0) {
            cout << abs(y) - abs(x) + 1 << endl;
        } else if (x < 0 && y < 0) {
            cout << abs(y) - abs(x) + 2 << endl;
        } else if (x == 0) {
            if (y > 0)
                cout << y << endl;
            else if (y < 0)
                cout << abs(y) + 1 << endl;
        }
    } else if (abs(x) > abs(y)) {
        if (x > 0 && y > 0) {
            cout << abs(x) - abs(y) + 2 << endl;
        } else if (x > 0 && y < 0) {
            cout << abs(x) - abs(y) + 1 << endl;
        } else if (x < 0 && y > 0) {
            cout << abs(x) - abs(y) + 1 << endl;
        } else if (x < 0 && y < 0) {
            cout << abs(x) - abs(y) << endl;
        } else if (y == 0) {
            if (x > 0) {
                cout << 1 + x << endl;
            } else if (x < 0) {
                cout << abs(x) << endl;
            }
        }
    } else if (abs(x) == abs(y)) {
        if ((x >= 0 && y >= 0) || (x < 0 && y < 0)) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }

    return 0;
}