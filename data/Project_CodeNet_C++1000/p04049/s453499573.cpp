#include <vector>
#include <iostream>
using namespace std;

vector<int> adj[2000];

int dfs(int i, int k, int p=-1) {
    int ans = 0;
    for (int j : adj[i]) if (j != p) ans += dfs(j, k-1, i);
    return ans + (k < 0 ? 1 : 0);
}

int main() {
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        int sum = dfs(i, k/2);
        ans = min(ans, sum);

        if (k % 2) {
            for (int j : adj[i]) {
                ans = min(ans, sum + dfs(j, (k+1)/2-1, i) - dfs(j, k/2-1, i));
            }
        }
    }
    cout << ans << endl;
}
