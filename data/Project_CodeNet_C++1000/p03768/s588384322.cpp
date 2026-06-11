#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
//#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;
const int N = 200000;
int n, s;
vector < int > g[N];
vector < pair < int, int > > a[11][N];
int ans[N], t[N];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> q;
    for (int i = 1; i <= q; i++){
        int v, d, c;
        cin >> v >> d >> c;
        a[d][v].pb({i, c});
    }
    for (int i = 10; i >= 0; i--){
        for (int j = 1; j <= n; j++){
            if (a[i][j].empty()) continue;
            sort(a[i][j].begin(), a[i][j].end());
            reverse(a[i][j].begin(), a[i][j].end());
            auto x = a[i][j][0];
            if (t[j] < x.F){
                ans[j] = x.S;
                t[j] = x.F;
            }
            if (i != 0)
            for (auto u: g[j]){
                a[i - 1][u].pb(x);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
