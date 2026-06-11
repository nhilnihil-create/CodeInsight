#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

vector <vector <int>> g;
int h[N];

int ans = 0;

const int Inf = 1e9;

int k;

void dfs(int u, int p) {
    for (auto v : g[u]) {
        dfs(v, u);
        h[u] = max(h[u], h[v] + 1);
    }
    if (p != 0 && h[u] == k - 1) {
        ++ans;
        h[u] = -Inf;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    g.resize(n);
    for (int i = 1; i < n; ++i) g[a[i]].push_back(i);
    if (a[0] != 0) {
        ++ans;
    }
    dfs(0, 0);
    cout << ans << '\n';
}