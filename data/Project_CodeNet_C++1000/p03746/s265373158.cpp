#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+1;
vector<int> graph[MAX_N], ans;
bool visited[MAX_N];

void dfs(int x) {
    visited[x] = true;
    ans.push_back(x);
    for (int i : graph[x]) {
        if (!visited[i]) {
            dfs(i);
            break;
        }
    }
}

int main() {
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    reverse(ans.begin(), ans.end());
    ans.pop_back();
    dfs(1);

    cout << ans.size() << endl;
    for (int i: ans) {
        cout << i << " ";
    }
    cout << endl;
}