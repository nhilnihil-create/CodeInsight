#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), c(m);
    vector<vector<int>> dist(n, vector<int>(n, 1e7));
    rep(i, n) dist[i][i] = 0;
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
        dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
    }
    rep(k, n) rep(i, n) rep(j, n) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    int ans = m;
    rep(i, m) {
        bool isCandidate = false;
        rep(s, n) rep(t, n) {
            if (s == t) continue;
            if (dist[s][t] == dist[s][a[i]] + c[i] + dist[b[i]][t]) {
                isCandidate = true;
            }
        }
        if (isCandidate) ans--;
    }
    cout << ans << endl;
}