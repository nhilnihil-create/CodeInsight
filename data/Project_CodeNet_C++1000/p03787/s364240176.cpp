#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define ll long long
#define int long long
#define ld long double
#define pii pair <int , int>
#define pll pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

const int maxn = 3e5 + 2 , N = 2e6 + 10 , SQ = 320 , base = 1999 , mod = 1e9 + 7 , INF = -1e9 , lg = 33;

int n , m , u , v , p, c , t[2] , h[maxn] , mark[maxn];
int ans;
vector <int> g[maxn];

void dfs(int x) {
    mark[x]=1;
    for (int i = 0; i < g[x].size(); ++i)
        if(mark[g[x][i]] && h[x] == h[g[x][i]])
            c = 1;
    for (int i = 0; i < g[x].size(); ++i)
        if(!mark[g[x][i]])
            h[g[x][i]] = h[x] ^ 1 , dfs(g[x][i]);
}

int32_t main() {
    cin >> n >> m;
    p = n;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u].PB(v);
        g[v].PB(u);
    }
    for (int i = 1; i <= n; ++i)
        if(!mark[i]) {
            if(g[i].size()) {
                c = 0;
                dfs(i);
                t[c]++;
            }
            else ans += p * 2 - 1 , p--;
        }
    ans += 1ll * (t[0] + t[1]) * (t[0] + t[1]) + 1ll * t[0] * t[0];
    cout << ans;
}
