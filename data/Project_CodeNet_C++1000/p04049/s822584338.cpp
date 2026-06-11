#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> G[2010];
int a[2010], b[2010];
bool used[2010];
int dfs(int nd, int d) {
    int ans = (d > k / 2);
    for (int i = 0; i < G[nd].size(); i++) {
        if (used[G[nd][i]]) continue;
        used[G[nd][i]] = 1;
        ans += dfs(G[nd][i], d+1);
    }
    return ans;
}
 
int main() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    int ans = n;
    if (k&1) {
        for (int i = 0; i < n - 1; i++) {
            memset(used,0,sizeof(used));
            used[a[i]] = 1;
            used[b[i]] = 1;
            ans = min(ans, dfs(a[i], 0) + dfs(b[i], 0));
        }
    } else {
        for (int i = 0; i < n; i++) {
            memset(used,0,sizeof(used));
            used[i] = 1;
            ans = min(ans, dfs(i,0));
        }
    }
    cout << ans << endl;
    return 0;
}