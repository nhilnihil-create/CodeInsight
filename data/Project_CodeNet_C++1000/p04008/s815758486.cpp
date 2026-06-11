#include <vector>
#include <numeric>
#include <functional>
#include <iostream>
using namespace std;
int a[30][100100];
int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[0][i], a[0][i]--;
    for (int e = 1; e < 30; e++)
        for (int i = 0; i < n; i++) a[e][i] = a[e-1][a[e-1][i]];
    int kth[n];
    iota(kth, kth+n, 0);
    for (int e = 29; e >= 0; e--)
        if ((k >> e) & 1)
            for (int i = 0; i < n; i++) kth[i] = a[e][kth[i]];
    if (count(kth, kth+n, 0) == n) {
        cout << "0\n";
        return 0;
    }
    int dist[n];
    fill(dist, dist+n, -1);
    dist[0] = 0;
    function<int(int)> calc_dist = [&](int i) {
        if (dist[i] >= 0) return dist[i];
        else return dist[i] = 1 + calc_dist(a[0][i]);
    };
    for (int i = 1; i < n; i++) {
        calc_dist(i);
    }
    if (all_of(dist, dist+n, [&k](int d) { return d <= k; })) {
        cout << "1\n";
        return 0;
    }

    vector<int> adj[n];
    for (int i = 1; i < n; i++) adj[a[0][i]].push_back(i);
    pair<int, int> dp[n];
    int ans = a[0][0] == 0 ? 0 : 1;
    function<int(int)> dfs = [&](int i) {
        int height = 1;
        for (int j : adj[i]) height = max(height, 1 + dfs(j));
       if (height == k && i != 0 && a[0][i] != 0) { ans++; return 0; }
        else return height;
    };
    dfs(0);
    cout << ans << endl;
}
