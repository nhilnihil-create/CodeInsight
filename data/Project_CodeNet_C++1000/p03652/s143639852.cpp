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
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ans = n;
    vector<int> b(m);
    vector<int> p(n);
    while (true) {
        vector<int> c(m);
        if (accumulate(b.begin(), b.end(), 0) >= m - 1) {
            break;
        }
        for (int i = 0; i < n; i++) {
            while (b[a[i][p[i]]]) {
                p[i]++;
            }
            c[a[i][p[i]]]++;
        }
        ans = min(ans, *max_element(c.begin(), c.end()));
        vector<int> t;
        int mx = *max_element(c.begin(), c.end());
        for (int i = 0; i < m; i++) {
            if (c[i] == mx) {
                t.emplace_back(i);
            }
        }
        for (int i : t) {
            b[i] = 1;
        }
    }
    cout << ans << '\n';
    return 0;
}