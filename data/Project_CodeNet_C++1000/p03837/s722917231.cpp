#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int inf = 1000000000;

int main() {
    int n, m; cin >> n >> m;
    int e[m][3];
    for (int i = 0; i < m; i++) {
        cin >> e[i][0] >> e[i][1] >> e[i][2];
        e[i][0]--; e[i][1]--;
    }
    int d[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (i == j) d[i][j] = 0;
        else d[i][j] = inf;
    }
    for (int i = 0; i < m; i++) {
        d[e[i][0]][e[i][1]] = e[i][2];
        d[e[i][1]][e[i][0]] = e[i][2];
    }
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    int ans = m;
    for (int i = 0; i < m; i++) { //辺iがある頂点間の最短経路に使われるか
        bool found = false;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (d[j][k] == d[j][e[i][0]] + e[i][2] + d[e[i][1]][k]) {
                    ans--;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }
    cout << ans << endl;
}