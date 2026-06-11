#include<bits/stdc++.h>
using namespace std;

const int N = 2005;
vector<int> adj[N];

int dfs(int u, int p, int dep, int k) {
    if (dep > k)    return 0;
    int ans = 1;
    for (int v: adj[u])
        if (v != p)
            ans += dfs(v, u, dep+1, k);
    return ans;
}

int solve(int s, int k) {
    int a = k/2, b = k-k/2;

    int ans = 0, mx = 0;
    for (int v: adj[s]) {
        int x = dfs(v, s, 1, a);
        int y = dfs(v, s, 1, b);
        ans += x;
        mx = max(mx, y-x);
    }
    return 1+ans+mx;
}

int main() {
    int n, k;
    cin>>n>>k;

    for (int i=1; i<n; i++) {
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i=1; i<=n; i++)    ans = max(ans, solve(i, k));
    cout<<n-ans<<endl;
}
