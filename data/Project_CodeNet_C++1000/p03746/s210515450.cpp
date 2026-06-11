#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int a, b; cin >> a >> b; graph[a].emplace_back(b)) {
        graph[b].emplace_back(a);
    }
    vector<int> result = {1};
    vector<bool> visited(n + 1);
    function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        while (true) {
            bool flag = true;
            for (int i : graph[node]) {
                if (!visited[i]) {
                    flag = false;
                    visited[i] = true;
                    node = i;
                    result.emplace_back(node);
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
    };
    dfs(1);
    reverse(begin(result), end(result));
    dfs(1);
    cout << result.size() << '\n';
    for (auto it = result.rbegin(); it != result.rend(); it++) {
        cout << *it << ' ';
    }
    return 0;
}