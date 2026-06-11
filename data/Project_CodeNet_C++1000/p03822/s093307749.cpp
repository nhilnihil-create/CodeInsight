// Why am I so dumb? :c
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)1e5 + 5;

vector<int> adj[MAXN];

int n;

int dfs(int v) {
    vector<int> vv;

    for (int to : adj[v]) {
        vv.pb(dfs(to));
    }

    sort(all(vv));
    reverse(all(vv));

    int ret = adj[v].size();

    for (int i = 0; i < vv.size(); ++i) {
        ret = max(ret, vv[i] + i + 1);
    }

    return ret;
}

void solve() {
    scanf("%d", &n);

    for (int i = 2, x; i <= n; ++i) {
        scanf("%d", &x);
        adj[x].pb(i);
    }

    printf("%d\n", dfs(1));
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}