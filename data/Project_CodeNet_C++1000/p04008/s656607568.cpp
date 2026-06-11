#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int,int> PII;

int n, k, a[1<<17], ans, dp[1<<17];
vector <int> g[1<<17];

void dive(int u) {
    int val = 1;
    for (auto v : g[u]) if (v != u) {
        dive(v);
        val = max(val, dp[v] + 1);
    }
    if (val == k && a[u] != 1) dp[u] = 0, ans++;
    else dp[u] = val;
}

int main() {
    cin >> n >> k;
    cin >> a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        g[a[i]].push_back(i);
    }
    if (a[1] != 1) ans++, a[1] = 1;

    dive(1);
    cout << ans;
}
