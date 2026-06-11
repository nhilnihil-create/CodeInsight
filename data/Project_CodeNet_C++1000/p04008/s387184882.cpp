#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

const int N = int(2e5) + 7;
const int oo = int(1e9) + 7;

int n, k, a[N], change, d[N];
vector<int> g[N];

int DFS(int u) {
    if(d[u] != -1) return d[u];
    int dep = 0;
    int&res = d[u];
    for(int v: g[u]) {
        dep = DFS(v);
        if(dep == k - 1 && u != 1) ++change;
        else res = max(res, dep);
    }
    return res + 1;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    if(a[1] != 1) a[1] = 1, ++change;
    for(int i = 2; i <= n; ++i) g[a[i]].pb(i);
    memset(&d, -1, sizeof d);
    DFS(1);
    cout << change;
}
