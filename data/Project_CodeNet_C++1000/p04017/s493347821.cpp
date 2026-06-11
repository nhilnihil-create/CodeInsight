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

        int left = 1, right = r - l, ans = r - l;
        while (left <= right) {
            int mid = (left + right) >> 1;

            int v = l;
            for (int lvl = 21; lvl >= 0; lvl--)
                if (mid & (1 << lvl))
                    v = up[lvl][v];

            if (v >= r) {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
    return 0;
}
