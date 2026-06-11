#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];
int n;

static int dfs(int u, int far = -1) {
    int sg = 0;
    for (auto v: g[u]) if (v != far)
        sg^= dfs(v, u);
    return sg + 1; }

int main() {
#ifdef HOME
    freopen("dat.in", "r", stdin);
    freopen("dat.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int a, b, i = 1; i < n; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a); }

    cout << (dfs(1) > 1 ? "Alice" : "Bob") << endl;

    return 0; }
