///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long
#define sz(x) (int)x.size()
const int mx = 1000 * 100 + 5;
vector < int > ad[mx], ans;
bool mark[mx];
void dfs(int v){
	mark[v] = true;
	for(auto u : ad[v])
		if(!mark[u]){
			ans.pb(u);
			dfs(u);
			return;
		}
	return;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		u--, v--;
		ad[u].pb(v);
		ad[v].pb(u);
	}
	mark[v] = 1;
	dfs(u);
	reverse(ans.begin(), ans.end());
//	for(auto k : ans)
//		cout << k << endl;
	ans.pb(u);
	ans.pb(v);
	dfs(v);
	cout << sz(ans) << endl;
	for(auto k : ans)
		cout << k + 1 << " ";
	return 0;
}
