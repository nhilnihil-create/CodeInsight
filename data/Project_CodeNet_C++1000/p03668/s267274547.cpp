#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 998244353;
const int N = 520005;
const int K = 25;
vector < int > g[N];
int dp[N];
void dfs(int v, int p = -1){
    int c = 0;
    for (auto u: g[v]){
        if (u == p) continue;
        dfs(u, v);
        c ^= (dp[u] + 1);
    }
    dp[v] = c;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    if (dp[1] == 0) cout << "Bob"; else cout << "Alice";
}
