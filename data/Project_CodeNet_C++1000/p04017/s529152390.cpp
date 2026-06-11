#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, 0, n) cin >> x[i];
    int l, q;
    cin >> l >> q;
    vector<vector<int>> t(n + 1, vector<int>(18));
    rep(i, 0, n) {
        t[i][0] = upper_bound(x.begin(), x.end(), x[i] + l) - x.begin() - 1;
    }
    t[n][0] = t[n - 1][0] = n;
    rep(j, 1, 18) {
        rep(i, 0, n + 1) {
            t[i][j] = t[t[i][j - 1]][j - 1];
        }
    }
    rep(i, 0, n)
        debug(t[i]);
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b) swap(a, b);
        int ans = 0;
        for (int j = 17; j >= 0; j--) {
            if (j != 0 && t[a][j] <= b) {
                ans += 1 << j;
                a = t[a][j];
            }
            if (j == 0) {
                while (a < b) {
                    ans++;
                    a = t[a][0];
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}