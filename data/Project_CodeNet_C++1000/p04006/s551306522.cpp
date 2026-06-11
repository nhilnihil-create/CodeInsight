#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

typedef long long llint;

llint n, x, sol;
llint a[MAXN * 2], mn[MAXN][MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        mn[0][i] = a[i];
        sol += a[i];
    }
    for (int ofs = 1; ofs < n; ofs++) {
        llint res = ofs * x;
        for (int i=0; i<n; i++) {
            mn[ofs][i] = min(mn[ofs - 1][i], a[n + i - ofs]);
            res += mn[ofs][i];
        }
        sol = min(sol, res);
    }
    cout << sol;
    return 0;
}
