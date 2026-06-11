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

int arr[MAXN];

int n;

bool dfs(int v, int pr) {
    vector<int> vv;
    ll k = arr[v] * 2;

    for (int to : adj[v]) {
        if (to == pr) {
            continue;
        }

        if (!dfs(to, v)) {
            return 0;
        }

        k -= arr[to];
        vv.pb(arr[to]);
    }

    if (vv.empty()) {
        return 1;
    }

    if (vv.size() == 1) {
        return arr[v] == vv[0];
    }

    if (k < 0 || k > arr[v]) {
        return 0;
    }

    vv.pb(k);
    ll sum = 0;

    for (int x : vv) {
        sum += x;
    }

    if (sum & 1) {
        return 0;
    }

    if (*max_element(all(vv)) > sum / 2) {
        return 0;
    }

    arr[v] = k;

    if (pr == -1 && arr[v] != 0) {
        return 0;
    }

    return 1;
}

void solve() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (n == 2) {
        printf(arr[1] == arr[2] ? "YES\n" : "NO\n");
        return;
    }

    int root = 1;

    while (adj[root].size() == 1) {
        ++root;
    }

    printf(dfs(root, -1) ? "YES\n" : "NO\n");
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}