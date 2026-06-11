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
#include <bitset>
using namespace std;
using llong = long long;

llong n, k;
llong a[16];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    llong ans = 1ll << 60ll;
    for (int i = 0; i < (1 << n); i++) {
        bitset<16> s(i);
        if (s.count() < k) continue;

        llong x = 0;
        llong maxv = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] && a[j] <= maxv) {
                x += maxv - a[j] + 1;
                maxv += 1;
            }
            else {
                maxv = max(maxv, a[j]);
            }
        }

        ans = min(ans, x);
    }

    cout << ans << endl;

    return 0;
}
