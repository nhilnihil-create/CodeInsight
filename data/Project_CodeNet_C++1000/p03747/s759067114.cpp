#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

// inf
constexpr ll infl = 10000000000000000LL;
constexpr int inf = 1000000000;

int main() {
    ll n, l, t;
    cin >> n >> l >> t;
    vector<ll> x(n), y(n), w(n);
    ll k = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> w[i];

        if (w[0] != w[i]) {
            if (w[0] == 1 && 2 * t >= x[i] - x[0]) {
                k += (2 * t - x[i] + x[0]) / (l) + 1;
            } else if (w[0] == 2 && 2 * t >= x[0] - x[i] + l) {
                k -= (2 * t - x[0] + x[i] - l) / (l) + 1;
            }
        }

        if (w[i] == 1)
            y[i] = (x[i] + t) % l;
        else
            y[i] = ((x[i] - t) % l + l) % l;
    }

    k = ((k % n) + n) % n;

    ll y0 = y[0];
    sort(y.begin(), y.end());
    int m = lower_bound(y.begin(), y.end(), y0) - y.begin();

    if (w[0] == 1 && m < n - 1 && y[m + 1] == y0)
        ++m;

    for (int i = 0; i < n; ++i) {
        x[(k + i) % n] = y[(m + i) % n];
    }

    for (int i = 0; i < n; ++i) {
        cout << x[i] << endl;
    }

    return 0;
}