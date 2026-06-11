#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
bool mark[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    deque<int> ans;
    ans.push_back(0);
    mark[0] = true;
    bool flag = true;
    while (flag) {
        flag = false;
        u = ans.back();
        for (auto v: adj[u])
            if (!mark[v]) {
                mark[v] = true;
                flag = true;
                ans.push_back(v);
                break;
            }
    }
    flag = true;
    while (flag) {
        flag = false;
        u = ans[0];
        for (auto v: adj[u])
            if (!mark[v]) {
                mark[v] = true;
                flag = true;
                ans.push_front(v);
                break;
            }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";
    cout << "\n";
}