#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;

int dp[NMAX];
vector <int> graph[NMAX];

void dfs(int node, int father) {
    for (auto it: graph[node])
        if (it != father) {
            dfs(it, node);
            dp[node] ^= dp[it];
        }
    if (father)
        ++ dp[node];
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i < N; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1, 0);
    if (dp[1])
        cout << "Alice\n";
    else
        cout << "Bob\n";
    return 0;
}