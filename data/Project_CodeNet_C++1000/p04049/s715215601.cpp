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
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 2007;
int n, k;
vector <int> g[N];
int dfs(int u, int p, int d) {
    if (d < 0)
        return 0;
    int ans = 1;
    for (int v : g[u]) {
        if (v != p) {
            ans += dfs(v, u, d - 1);
        }   
    }   
    return ans;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v);
        g[v].app(u);
    }   
    if (k % 2 == 0) {
        int ans = 0;
        for (int centr = 1; centr <= n; ++centr) {
            int nn = 1;
            for (int v : g[centr]) {
                nn += dfs(v, centr, k / 2 - 1);                        
            }   
            ans = max(ans, nn);
        }   
        cout << n - ans << endl;
    }
    else {
        int ans = 0;
        for (int centr = 1; centr <= n; ++centr) {
            int nn = 1, add = 0;
            for (int v : g[centr]) {
                int a = dfs(v, centr, k / 2 - 1);
                int b = dfs(v, centr, (k + 1) / 2 - 1);
                nn += a;
                add = max(add, b - a);
            }   
            nn += add;
            ans = max(ans, nn);
        }   
        cout << n - ans << endl;
    }   

}