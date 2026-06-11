#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > adj;
int solve(int i, int p) {
    int g = 0;
    for (int j : adj[i]) if (j != p) g ^= 1 + solve(j, i);
    return g;
}

int main() {
    int n; cin >> n;
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    cout << (solve(0, -1) == 0 ? "Bob" : "Alice") << endl;
}
