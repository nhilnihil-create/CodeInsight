#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 2);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        int d = r - l + 1, u = 2e7;
        a[1]++;
        a[d + 1]--;
        for (int j = 1; j < 340; j++) {
            int nl = (l + j - 1) / j, nr = r / j;
            nl = max(d + 1, nl);
            nr = min(u - 1, nr);
            if (nr < nl) {
                continue;
            }
            a[nl]++;
            a[nr + 1]--;
            u = nl;
        }
        for (int k = d + 1; k < min({u, 340, m + 1}); k++) {
            if ((l + k - 1) / k <= r / k) {
                a[k]++;
                a[k + 1]--;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << a[i] << endl;
        a[i + 1] += a[i];
    }
    return 0;
}