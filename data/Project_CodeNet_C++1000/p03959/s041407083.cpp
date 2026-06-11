#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

const llong mod = (llong)1e9 + 7;
llong n;
llong a[100005];
llong b[100005];
llong maxv = 0;
llong cnt = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxv = max(maxv, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        maxv = max(maxv, b[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i] && a[i] == maxv) cnt++;
    }

    llong ans = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i - 1] || b[i] > b[i + 1]) continue;
        ans *= min(a[i], b[i]);
        ans %= mod;
    }

    if (cnt) cout << ans << endl;
    else cout << 0 << endl;

    return 0;
}
