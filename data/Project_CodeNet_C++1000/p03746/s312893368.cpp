#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M; cin >> N >> M;
    vector<bool> visited(N);
    vector<vector<int>> graph(N);
    deque<int> path;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int curr = 0;
    while (!visited[curr]) {
        visited[curr] = true;
        path.push_back(curr);
        for (int n : graph[curr]) if (!visited[n]) { curr = n; break; }
    }
    curr = 0, visited[0] = false, path.pop_front();
    while (!visited[curr]) {
        visited[curr] = true;
        path.push_front(curr);
        for (int n : graph[curr]) if (!visited[n]) { curr = n; break; }
    }
    cout << path.size() << '\n';
    for (int i = 0; i < path.size(); i++) {
        if (i != 0) cout << ' ';
        cout << path[i] + 1;
    }
    cout << '\n';
    return 0;
}