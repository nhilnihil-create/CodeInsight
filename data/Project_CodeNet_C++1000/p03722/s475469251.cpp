#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1005;
vector < pair < int, int > > g[maxn];
int answer[maxn];
int ok[maxn], used[maxn], check[maxn];
int inf = 1e18;

void dfs(int v, int i) {
    used[v] = i;
    for (auto u : g[v]) {
        if (used[u.first] != i) dfs(u.first, i);
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    for (int i = 2; i <= n; ++i) answer[i] = -inf;
    for (int i = 1; i <= n; ++i) {
        dfs(i, i);
        ok[i] = (used[n] == i);
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (auto u : g[j]) {
                answer[u.first] = max(answer[u.first], answer[j] + u.second);
            }
        }
    }
    for (int j = 1; j <= n; ++j) {
        for (auto u : g[j]) {
            if (answer[u.first] < answer[j] + u.second) check[u.first] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (check[i] && ok[i]) {
            cout << "inf";
            exit(0);
        }
    }
    cout << answer[n];
    return 0;
}
