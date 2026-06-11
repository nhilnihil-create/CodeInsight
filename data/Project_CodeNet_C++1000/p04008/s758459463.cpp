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
const int N = 200000;
int n, s;
vector < int > ans;
vector < int > g[N];
set < int > h[N];
int a[N], p[N], dep[N];
void dfs(int v, int c, int d = 0, int pr = -1){
    if (c == 1)
    h[d].insert(v); else{
        if (h[d].find(v) == h[d].end()) return;
        h[d].erase(v);
    }
    p[v] = pr;
    dep[v] = d;
    //cout << v << endl;
    for (auto u: g[v]){
        dfs(u, c, d + 1, v);
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (i != 1)
        g[a[i]].pb(i);
	}
	int ans = 0;
	if (a[1] != 1) ans++;
	dfs(1, 1);
	p[1] = 1;
	//cout << "!" << endl;
	for (int i = n; i > k; i--){
        while(!h[i].empty()){
            ans++;
            int v = *h[i].begin();
            for (int j = 1; j < k; j++){
                v = p[v];
            }
          //  cout << "v = " << v << endl;
            dfs(v, 0, dep[v]);
        }
	}
	cout << ans;
}
