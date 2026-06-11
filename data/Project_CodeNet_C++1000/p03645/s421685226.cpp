#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<int, vector<int>> graf;
bool ok = 0;
void dfs(int v, int deep) {
    if(deep >= 2) {
        if(v == n) {
            ok = 1;
        }
        return;
    }
    for (auto x : graf[v]) {
        dfs(x, deep + 1);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
    }
    dfs(1, 0);
    if(ok) {
        cout << "POSSIBLE";
    }
    else {
        cout << "IMPOSSIBLE";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
