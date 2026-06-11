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
int n, a[N];
int dfs(int u, int p) {
    int sum = 0, mx = 0;
    bool lief = 1;
    for (int v : g[u]) {
        if (v != p) {
            lief = 0;
            int x = dfs(v, u);
            sum += x;
            mx = max(mx, x);
        }   
    }   
    if (lief) return a[u];
    if (sum < a[u]) {
        cout << "NO\n";
        exit(0);
    }   
    int wp = sum - a[u];
    int maxp;
    if (mx * 2 <= sum) maxp = sum >> 1;
    else maxp = sum - mx;
    if (wp > maxp) {
        cout << "NO\n";
        exit(0);
    }   
    return sum - wp * 2;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    if (n == 2) {
        if (a[1] == a[2]) cout << "YES\n";
        else cout << "NO\n";
        exit(0);
    }   
    int r = -1;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() > 1) {
            r = i;
        }   
    }   
    if (!dfs(r, r)) cout << "YES\n";
    else cout << "NO\n";
}       