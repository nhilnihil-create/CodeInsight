/**
 *    author:  FromDihPout
 *    created: 2020-08-04
**/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> a(r);
    for (int i = 0; i < r; i++) {
        cin >> a[i];
        a[i]--;
    }
    
    vector<vector<int>> dist(n, vector<int> (n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    sort(all(a));
    int ans = INF;
    do {
        int curr_dist = 0;
        for (int i = 1; i < r; i++) {
            curr_dist += dist[a[i]][a[i-1]];
        }
        ans = min(ans, curr_dist);
    } while (next_permutation(all(a)));
    
    cout << ans << '\n';
    return 0;
}