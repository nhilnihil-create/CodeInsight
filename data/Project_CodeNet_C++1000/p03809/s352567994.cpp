#include<bits/stdc++.h>
using namespace std;

void no() {
    cout<<"NO"<<endl;
    exit(0);
}

const int N = 1e5+7;

vector<int> adj[N];
int a[N];
long long up[N];
long long leafsum = 0;

void dfs(int u, int p) {
    if (adj[u].size() == 1) {
        up[u] = a[u];
        return ;
    }

    long long mx = 0;
    up[u] = 2*a[u];
    for (int v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        up[u] -= up[v];
        mx = max(mx, up[v]);
    }

    if (up[u] < 0)  no();
    mx = max(mx, up[u]);
    if (mx > a[u])  no();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for (int i=1; i<=n; i++)    cin>>a[i];

    for (int i=1; i<n; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 2) {
        if (a[1] == a[2])   cout<<"YES\n";
        else                cout<<"NO\n";
        return 0;
    }

    int root = 0;
    for (int i=1; i<=n; i++)
        if (adj[i].size() > 1) {
            if (!root)  root = i;
        }

    dfs(root, 0);
    if (up[root])   no();
    cout<<"YES\n";
}
