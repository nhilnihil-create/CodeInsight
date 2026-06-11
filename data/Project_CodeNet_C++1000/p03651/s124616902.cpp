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

llong n, k;
llong a[100005];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    llong g = __gcd(a[0], a[1]);
    for (int i = 2; i < n; i++) {
        g = __gcd(g, a[i]);
    }

    bool f = false;
    for (int i = 0; i < n; i++) {
        if (a[i] >= k && k % g == 0) f = true;
    }

    if (f) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}
