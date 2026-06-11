/**
 *    author:  FromDihPout
 *    created: 2020-08-02
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<bool> start(n+1), end(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == 1) {
            start[v] = true;
        }
        else if (v == n) {
            end[u] = true;
        }
    }
    
    for (int i = 2; i < n; i++) {
        if (start[i] && end[i]) {
            cout << "POSSIBLE" << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}