#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n; ll a[maxn];
vector<int> G[maxn];

ll dfs(int v, int f) {
    if (G[v].size() == 1) return a[v];
    ll sum = 0;
    vector<ll> V;
    for (int u : G[v]) if (u ^ f) {
        ll t = dfs(u, v);
        sum += t, V.push_back(t);
    }
    ll ub = sum - a[v];
    if (ub < 0) printf("NO\n"), exit(0);
    for (ll x : V) {
        ll t = min(x, sum - x);
        if (t + (sum - x - t) / 2 < ub) printf("NO\n"), exit(0);
    }
    a[v] -= ub, sum -= ub * 2;
    if (a[v] < 0) printf("NO\n"), exit(0);
    if (!f && sum) printf("NO\n"), exit(0);
    return sum;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    if (n == 2) {
        printf("%s\n", a[1] == a[2] ? "YES" : "NO"), exit(0);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (G[i].size() > 1) { dfs(i, 0); break; }
    }
    printf("YES\n");
    return 0;
}