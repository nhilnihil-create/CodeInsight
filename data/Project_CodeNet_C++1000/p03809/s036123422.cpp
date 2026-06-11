#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100100;

ll a[N], b[N];
vector<pair<int, int>> g[N];
int used[N];

void dfs(int v, int from = -1) {
    used[v] = 1;
    for (auto p : g[v]) {
        if (used[p.first]) {
            continue;
        }
        dfs(p.first, p.second);
    }
    ll t = 0;
    for (auto p : g[v]) {
        if (p.second != from) {
            t += b[p.second];
        }
    }
    if (v == 1) {
        if (t != a[1] + a[1] * (g[v].size() > 1)) {
            cout << "NO";
            exit(0);
        }
        return;
    }
    if (g[v].size() == 1) {
        b[from] = a[v];
    } else {
        if (t > 2 * a[v]) {
            cout << "NO";
            exit(0);
        }
        b[from] = 2 * a[v] - t;
    }
}

void check(int v) {
    used[v] = 1;
    for (auto p : g[v]) {
        if (!used[p.first]) {
            check(p.first);
        }
    }
    if (g[v].size() == 1) {
        return;
    }
    ll t = 0;
    ll m = 0;
    for (auto p : g[v]) {
        t += b[p.second];
        m = max(m, b[p.second]);
    }
    if (t % 2 || m > t / 2) {
        cout << "NO";
        exit(0);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back({t2, i});
        g[t2].push_back({t1, i});
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        used[i] = 0;
    }
    check(1);
    cout << "YES";
    return 0;
}