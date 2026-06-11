#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX_N = 1e5 + 1;

bool is_visited[MAX_N];
vector<int> graph[MAX_N];
vector<int> ans1, ans2;

void dfs(int node, vector<int>& ans) {
    is_visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        if (is_visited[graph[node][i]]) continue;
        dfs(graph[node][i], ans);
        break;
    }
    ans.push_back(node + 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0, ans1);
    dfs(0, ans2);
    reverse(ans2.begin(), ans2.end());
    int node_size = ans1.size() + ans2.size() - 1;
    cout << node_size << endl;
    for (int i = 0; i < ans1.size(); i++) cout << ans1[i] << ' ';
    for (int i = 1; i < ans2.size(); i++) cout << ans2[i] << ' ';
    cout << endl;
    return 0;
}