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
const int mod = 1e9 + 7;
const int N = 200005;
const int K = 10;
int a[N], d[N];
vector < int > g[N];
map < pair < int, int >, int > mp;
int binpow(int x, int y){
    if (y == 0) return 1;
    if (y % 2) return x * binpow(x, y - 1) % mod;
    int z = binpow(x, y / 2);
    return z * z % mod;
}
int dfs(int v, int p = -1){
    int mx = 0;
    int s = 0;
    for (auto u: g[v]){
        if (u == p) continue;
        int x = dfs(u, v);
        s += x;
        mx = max(mx, x);
    }
   // cout << "v = " << v << endl;
    if (d[v] == 1) return a[v];
    int x = 2 * a[v] - s;
    int y = s - a[v];
   // cout << v << " " << x << " " << y << " " << mx << " " << s << " " << a[v] << endl;
    if (y > s - mx || y < 0 || x < 0){
        cout << "NO";
        exit(0);
    }
    if (p == -1){
        if (x == 0){
            cout << "YES";
        } else cout << "NO";
        exit(0);
    }
    return x;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        d[u]++;
        d[v]++;
    }
    if (n == 2){
        if (a[1] == a[2]){
            cout << "YES";
        } else{
            cout << "NO";
        }
        return 0;
    }
    for (int i = 1; i <= n; i++){
        if (d[i] != 1){
            dfs(i);
        }
    }
}
