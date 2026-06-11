#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1000000000;

int main() {
    int n, m; cin >> n >> m;
    tuple<int, int, int> e[m];
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        e[i] = make_tuple(a, b, c);
    }
    int d[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = INF;
    for (int i = 0; i < n; i++) { //各頂点から考える
        d[i][i] = 0;
        bool update = true;
        while (update) {
            update = false;
            for (int j = 0; j < m; j++) {
                int a, b, c;
                tie(a, b, c) = e[j];
                if (d[i][a] > d[i][b] + c) {
                    d[i][a] = d[i][b] + c;
                    update = true;
                }
                if (d[i][b] > d[i][a] + c) {
                    d[i][b] = d[i][a] + c;
                    update = true;
                }
            }
        }
    }
    bool used[m];
    for (int i = 0; i < m; i++) used[i] = false;
    for (int i = 0; i < n; i++) { //各頂点から考える
        for (int j = 0; j < m; j++) { //頂点iからの最短経路に辺jが使われるか
            if (used[j]) continue;
            int a, b, c;
            tie(a, b, c) = e[j];
            for (int k = 0; k < n; k++) { //頂点iからkへの最短経路について
                if (d[i][k] == d[i][a] + c + d[b][k] || d[i][k] == d[i][b] + c + d[a][k]) {
                    used[j] = true;
                    break;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (!used[i]) ans++;
    }
    cout << ans << endl;
}