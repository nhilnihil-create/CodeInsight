#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
vector <int> g[N];
bool used[N], col[N];
vector <int> comp;
void dfs(int u) {
    comp.app(u);
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) {
            col[v] = col[u] ^ 1;
            dfs(v);
        }   
    }   
}   
int cnt[3];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        if (g[i].empty()) {
            ++t;
            continue;
        }   
        if (!used[i]) {
            comp.clear();
            dfs(i);
            bool b = 1;
            for (int u : comp) {
                for (int v : g[u]) {
                    b &= col[u] != col[v];
                }   
            }   
            ++cnt[b];
        }   
    }
    cout << (cnt[0] + cnt[1]) * (cnt[0] + cnt[1]) + cnt[1] * cnt[1] + t * n + (n - t) * t << '\n';
}