///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long
#define sz(x) (int)x.size()
const int mx = 2002;
int n, k, t, h[mx];
vector < int > ad[mx];
vector < pair < int , int > > e;
bool mark[mx];
void dfs(int v){
	mark[v] = true;
	for(auto u : ad[v])
		if(!mark[u]){
			h[u] = h[v] + 1;
			if(h[u] > k / 2)
				t++;
			dfs(u);
		}
	return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int u, v, ans = 2002;
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v;
		u--, v--;
		ad[u].pb(v);
		ad[v].pb(u);
		e.pb({u , v});
	}
	if(!(k % 2)){
		for(int i = 0; i < n; i++){
			memset(mark , 0 , sizeof mark);
			h[i] = 0;
			t = 0;
			dfs(i);
			ans = min(ans , t);
		//	cout << i << " " << t << endl;
		}
	}
	else{
		for(int i = 0; i < n - 1; i++){
			memset(mark , 0 , sizeof mark);
			h[e[i].f] = h[e[i].s] = 0;
			mark[e[i].f] = mark[e[i].s] = true;
			t = 0;
			dfs(e[i].f); dfs(e[i].s);
		//	cout << e[i].f << " " << dfs(e[i].f) << endl;
			ans = min(ans , t);
		}
	}
	cout << ans << endl;
	return 0;
}
