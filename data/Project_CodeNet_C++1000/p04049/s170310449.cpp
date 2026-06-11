#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;
const int inf = 3000;
const int maxSize=4000;
int n, k;
vector<vector<int> > g(maxSize, vector<int>());
vector<int> subtree;
vector<vector<int> > dp(maxSize, vector<int>());
vector<vector<int> > minn(maxSize, vector<int>());// minn[v][dep] = min over dp[v][0], ..., dp[v][dep]
void dfs(int v, int p)
{
    subtree[v] = 1;
    vector<int> sons;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            sons.pb(to);
            subtree[v] += subtree[to];
        }
    }
    dp[v][0] = subtree[v] - 1;
    for (int dep = 1; dep < k; ++dep) {
        int x = min(dep - 1, k - dep - 1);
        int s = 0;
        for (int son : sons) {
            s += minn[son][x];
        }
        for (int son : sons) {
            dp[v][dep] = min(dp[v][dep], dp[son][dep - 1] + s - minn[son][x]);
        }
    }
    int s = subtree[v] - 1;
    for (int son : sons) {
        dp[v][k] = min(dp[v][k], dp[son][k - 1] + s - subtree[son]);
    }
    minn[v][0] = dp[v][0];
    for (int dep = 1; dep <= k; ++dep) {
        minn[v][dep] = min(minn[v][dep - 1], dp[v][dep]);
    }
}

int main()
{

    cin >> n >> k;
    g.resize(n);
    dp.resize(n);
    subtree.resize(n);
    minn.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i = 0; i < n; ++i) {
        dp[i].assign(k + 1, inf);
        minn[i].resize(k + 1);
    }

    dfs(0, 0);
    /*for (int v = 0; v < n; ++v) {
        for (int dep = 0; dep <= k; ++dep) {
            cout << v << " " << dep << " " << dp[v][dep] << "\n";
        }
    }*/
    int ans = inf;
    for (int dep = 0; dep <= k; ++dep) {
        ans = min(ans, dp[0][dep]);
    }
    for (int v = 1; v < n; ++v) {
        for (int dep = 0; dep <= k; ++dep) {
            ans = min(ans, dp[v][dep] + n - subtree[v]);
        }
    }
    cout << ans << "\n";

}