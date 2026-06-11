#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;

ll solve(ll N, ll M);

int main() {

    ll N, M;

    cin >> N >> M;

    ll ans;

    if (abs(N - M) > 1) {
        ans = 0;
    }
    else {
        ans = solve(N, M);
    }

    cout << ans;

    return 0;
}

ll solve(ll N, ll M) {
    ll tmp = 1, x = pow(10, 9) + 7;

    repl(i, 1, N + 1) {
        tmp *= i;
        if (tmp > x) {
            tmp %= x;
        }
    }
    repl(i, 1, M + 1) {
        tmp *= i;
        if (tmp > x) {
            tmp %= x;
        }
    }
    if (N == M) {
        tmp *= 2;
        if (tmp > x) {
            tmp %= x;
        }
    }

    return tmp;
}

