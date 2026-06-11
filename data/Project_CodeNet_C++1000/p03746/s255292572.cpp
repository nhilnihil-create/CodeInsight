#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<vector<int>> E;
array<vector<int>, 2> route;

void dfs(int i, int num, int route_num){
    route[route_num].push_back(i);
    int cnt = 0;
    for (const auto &e: E[i]){
        if (visited[e])
            continue;
        visited[e] = true;
        dfs(e, 1, route_num++);
        if (++cnt >= num)
            break;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    E.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    visited[1] = true;
    dfs(1, 2, 0);

    cout << route[0].size() + route[1].size() << endl;
    copy(route[0].rbegin(), route[0].rend(), ostream_iterator<int>(cout, " "));
    copy(route[1].begin(), route[1].end(), ostream_iterator<int>(cout, " "));
        
}