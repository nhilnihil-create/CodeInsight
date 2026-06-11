#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> color;

void dfs(int prev, int now, int remain, int c) {
    for (int i = remain; i >= 0 && color[now][i] == 0; i--) color[now][i] = c;

    if (remain == 0)return;
    for (auto next:graph[now]) {
        if (next == prev || color[next][remain - 1] != 0)continue;
        dfs(now, next, remain - 1, c);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        graph[a].push_back(b), graph[b].push_back(a);
    }

    int q;
    cin >> q;
    vector<vector<int>> operation(q);
    for (int i = 0; i < q; i++) {
        int v, d, c;
        cin >> v >> d >> c, v--;
        operation[i] = {v, d, c};
    }
    reverse(operation.begin(), operation.end());

    color.assign(n, vector<int>(11));
    for (auto x:operation) {
        if (color[x[0]][x[1]] != 0)continue;
        dfs(-1, x[0], x[1], x[2]);
    }

    for (int i = 0; i < n; i++)cout << color[i][0] << endl;
    return 0;
}