#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {

    ll K, S;
    cin >> K >> S;

    ll ans = 0;

    rep(i, min(K + 1, S + 1)) {
        rep(j, min(K + 1, S + 1)) {
            if (i + j <= S && i + j + K >= S) {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
