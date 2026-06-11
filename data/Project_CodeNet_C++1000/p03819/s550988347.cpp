#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()

const int N = 3e5 + 5;
int n, m, it[N], ans[N];
ii e[N];
vector<int> seg[N];
vector<ii> line[N];

void upd(int i, int val){
	for(; i <= 3e5; i += i & -i) it[i] += val;
}

int get(int i){
	int ans = 0;
	for(; i; i -= i & -i) ans += it[i];
	return ans;
}

main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> e[i].fi >> e[i].se;
	for(int i = 1; i <= n; ++i) seg[e[i].fi].pb(e[i].se);
	for(int i = 1; i <= m; ++i){
		ans[i] = n;
	}
	for(int i = 1; i <= m; ++i){
		for(int j = 0; j <= m; j += i){
			line[j+1].pb({min(m, i+j-1), i});
		}
	}
	for(int i=m; i; --i){
		for(auto &v : seg[i]) upd(v, 1);
		for(auto &v : line[i]) ans[v.se] -= get(v.fi);
	}
	for(int i=1; i<=m; ++i) cout<<ans[i]<<'\n';
}