#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

template <typename T>
T ceilDiv(T a, T b) {
    return a > 0 && b > 0 ? (a + b - 1) / b : a / b;
}

int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll l = ceilDiv((-a + b + c * (n - 1)), (c + d));
    ll r = (-a + b + d * (n - 1)) / (c + d);

    if (l > r || r < 0 || l > n - 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}