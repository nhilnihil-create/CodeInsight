#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

const int OO = int(1e8);
int a[2000], b[2000], c[2000];
int d[200][200];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, n) d[i][j] = (i == j ? 0 : OO);

    rep(i, 0, m) {
        cin >> a[i] >> b[i] >> c[i];
        --a[i]; --b[i];
        d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];
    }
    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int ans = 0;
    rep(t, 0, m) {
        bool need = false;
        int u = a[t], v = b[t];
        rep(i, 0, n) rep(j, 0, n)
        if (d[i][j] == d[i][u] + c[t] + d[v][j] || d[i][j] == d[i][v] + c[t] + d[u][j]) need = true;
        ans += (!need);
    }
    cout << ans << '\n';
}