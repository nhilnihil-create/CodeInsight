#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;
int vt[N], up[22][N];

void solve() {
    int n, L, q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> vt[i];
    }

    cin >> L;

    int rh = 1;
    for (int l = 1; l <= n; l++) {
        while (rh <= n && vt[rh] - vt[l] <= L)
            rh++;
        int r = rh - 1;
        up[0][l] = r;
    }

    for (int lvl = 1; lvl < 22; lvl++) {
        for (int v = 1; v <= n; v++) {
            up[lvl][v] = up[lvl - 1][up[lvl - 1][v]];
        }
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l > r)
            swap(l, r);

        int ans = 0;
        for (int lvl = 21; lvl >= 0; lvl--)
            if (up[lvl][l] < r) {
                ans += (1 << lvl);
                l = up[lvl][l];
            }
            
        ans++;
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
    return 0;
}
