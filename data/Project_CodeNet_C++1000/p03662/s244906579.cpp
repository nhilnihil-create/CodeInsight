#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;
const int maxn = 2e5 + 1e3;
vector<int> edges[maxn];
array<int, maxn> dis1, dis2;

void dfs(int current, int father, int dist, array<int, maxn> &cur) {
    cur[current] = dist;
    for (auto to:edges[current]) {
        if (to != father) {
            dfs(to, current, dist + 1, cur);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 0, 0, dis1);
    dfs(n, 0, 0, dis2);
    int balance = 0;
    for (int i = 1; i <= n; ++i) {
        balance += -1 + (dis1[i] <= dis2[i]) * 2;
    }
    if (balance > 0) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }
}
