#include <iostream>
#include <vector>
#include <stack>
#include <functional>
using namespace std;

int main() {
    int n, count[2] = {};
    cin >> n;
    vector<int> graph[n + 1], path;
    stack<int> nodes[2];
    for (int a, b; cin >> a >> b; ) {
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<bool> visited(n + 1);
    function<void(int, int)> dfs = [&](int root, int parent) {
        path.emplace_back(root);
        if (root == n) {
            for (int i = 0, j = 0, k = path.size() - 1; i < path.size(); i++) {
                visited[path[i]] = true;
                if (i % 2 == 0) {
                    nodes[0].emplace(path[j]);
                    j++;
                } else {
                    nodes[1].emplace(path[k]);
                    k--;
                }
            }
            return;
        }
        for (int i : graph[root]) {
            if (i != parent) {
                dfs(i, root);
            }
        }
        path.pop_back();
    };
    dfs(1, -1);
    for (int j : {0, 1}) {
        do {
            count[j]++;
            auto top = nodes[j].top();
            nodes[j].pop();
            for (int i : graph[top]) {
                if (!visited[i]) {
                    visited[i] = true;
                    nodes[j].emplace(i);
                }
            }
        } while (!nodes[j].empty());
    }
    if (count[1] >= count[0]) {
        cout << "Snuke";
    } else {
        cout << "Fennec";
    }
    return 0;
}
