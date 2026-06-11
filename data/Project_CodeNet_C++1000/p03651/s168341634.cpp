#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, k;
    cin >> n >> k;
    int g = 0, m = 0, x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        g = __gcd(g, x);
        m = max(m, x);
    }
    if (k > m || k % g)
        cout << "IMPOSSIBLE\n";
    else
        cout << "POSSIBLE\n";
}
