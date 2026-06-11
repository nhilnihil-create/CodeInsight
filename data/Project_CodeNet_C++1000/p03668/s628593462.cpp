#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int solve(const vector<vector<int>> &G, int node, int prev) {
    int ans = 0;
    for (auto &next : G[node]) if (next != prev) {
        ans ^= solve(G, next, node) + 1;
    }
    return ans;
}
int main() {
    int N; cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cout << (solve(G, 0, -1) ? "Alice" : "Bob") << '\n';
    return 0;
}
