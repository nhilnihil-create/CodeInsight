#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    vector<int> depth(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        vector<int> ds;
        for (int s : adj[v]) {
            if (s != p) {
                dfs(s, v);
                ds.push_back(depth[s]);
            }
        }
        sort(ds.begin(), ds.end());
        for (int i = 0; i < ds.size(); i++) {
            ds[ds.size() - 1 - i] += i;
        }
        sort(ds.begin(), ds.end());
        if (ds.size()) {
            depth[v] = ds.back() + 1;
        }
    };

    dfs(0, -1);
    cout << depth[0] << endl;
}