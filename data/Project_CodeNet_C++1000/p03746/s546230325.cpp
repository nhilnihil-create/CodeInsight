#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> G;
vector<int> ret1, ret2;
vector<int> used;

void dfs(int x) {
    for(int y : G[x]) {
        if(used[y] == 0) {
            ret1.push_back(y);
            used[y] = 1;
            dfs(y);
            break;
        }
    }
    return;
}

void dfs2(int x) {
    for(int y : G[x]) {
        if(used[y] == 0) {
            ret2.push_back(y);
            used[y] = 1;
            dfs2(y);
            break;
        }
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    G.resize(n+1);
    used.resize(n+1,0);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    used[0] = 1;
    ret1.push_back(0);
    dfs(0);
    dfs2(0);
    reverse(ret2.begin(), ret2.end());
    cout << ret1.size() + ret2.size() << endl;
    for(int x : ret2) {
        cout << x + 1 << " ";
    }
    for(int x : ret1) {
        cout << x + 1 << " ";
    }
    cout << endl;
    return 0;
}