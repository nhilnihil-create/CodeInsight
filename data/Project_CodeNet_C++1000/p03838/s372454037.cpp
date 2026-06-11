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

int main() {

    ll x, y;
    cin >> x >> y;

    ll ans;

    if (abs(x) == abs(y)) {
        ans = 1;
    }
    else if (x < y) {
        ans = abs(abs(y) - abs(x));
        if (abs(y) - abs(x) < y - x && y > 0) {
            ans += 1;
        }
    }
    else if (x > y) {
        ans = abs(abs(y) - abs(x)) + 2;
        if (y == 0) {
            ans--;
        }
        if (x == 0) {
            ans--;
        }
        if (x > 0 && y < 0) {
            ans --;
        }
    }

    cout << ans;
   
    return 0;
}
