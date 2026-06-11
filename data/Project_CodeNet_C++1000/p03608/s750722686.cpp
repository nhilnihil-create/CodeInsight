#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

ll d[205][205];

int main() {
    int n, m, R;
    cin >> n >> m >> R;
    int r[R];
    for (int i = 0; i < R; i++) {
        cin >> r[i];
        r[i]--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        d[a][b] = d[b][a] = c;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    sort(r, r + R);
    ll ans = INF;
    do {
        ll cnt = 0;
        for (int i = 1; i < R; i++) {
            cnt += d[r[i - 1]][r[i]];
        }
        ans = min(ans, cnt);
    } while (next_permutation(r, r + R));
    cout << ans << endl;
}