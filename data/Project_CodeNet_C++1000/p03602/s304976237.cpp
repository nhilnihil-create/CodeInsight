#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;
int n, a[maxn][maxn];
vector<pair<int, int>> E;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if (i ^ j && i < j) E.push_back(make_pair(i, j));
        }
    }
    sort(E.begin(), E.end(), [&](pair<int, int> p1, pair<int, int> p2) {
        return a[p1.first][p1.second] < a[p2.first][p2.second];
    });
    long long ans = 0;
    for (auto p : E) {
        int u = p.first, v = p.second, mn = 2e9;
        for (int i = 1; i <= n; i++) if (i ^ u && i ^ v) {
            mn = min(mn, a[u][i] + a[i][v]);
        }
        if (mn > a[u][v]) ans += a[u][v];
        else if (mn < a[u][v]) printf("-1\n"), exit(0);
    }
    printf("%lld\n", ans);
    return 0;
}