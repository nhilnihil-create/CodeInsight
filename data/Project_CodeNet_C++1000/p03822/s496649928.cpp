#include <bits/stdc++.h>
using namespace std;

int dfs (const vector<vector<int>> &g, int v) {
    if (g[v].size() == 0) return 0;
    vector<int> dat;
    for (int u : g[v]) dat.push_back(dfs(g, u));
    sort(dat.begin(), dat.end(), greater<int>());
    for (int i = 0; i < dat.size(); i++) dat[i] += i + 1;
    return *max_element(dat.begin(), dat.end());
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }

    cout << dfs(g, 0) << '\n';

    return 0;
}