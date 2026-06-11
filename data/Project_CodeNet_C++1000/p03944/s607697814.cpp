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

    ll W , H, N;

    cin >> W >> H >> N;

    ll R = 0, L = W, B = 0, T = H, x, y, a;

    rep(i, N) {
        cin >> x >> y >> a;

        if (a == 1) {
            R = max(x, R);
        }
        if (a == 2) {
            L = min(x, L);
        }
        if (a == 3) {
            B = max(y, B);
        }
        if (a == 4) {
            T = min(y, T);
        }

    }

    ll ans;

    ans = max((ll)0, L - R) * max((ll)0, T - B);

    cout << ans;

    return 0;
}