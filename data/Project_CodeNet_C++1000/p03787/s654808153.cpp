#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector< int > adj[MAXN];
int n, m;
ll a, b, c;
bool h[MAXN], mark[MAXN];
bool ok = true;
void dfs(int u){
	//cout << u << endl;
	mark[u] = true;
	for(int i = 0; i < adj[u].size(); i ++){
		int v = adj[u][i];
		if( !mark[v] )
			h[v] = !h[u], dfs(v);
		else if(h[u] == h[v])  ok = false;
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i ++){
		int u, v;
		cin >> u >> v, u --, v --;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	for(int i = 0; i < n; i ++){
		if( !mark[i] ){
			ok = true;
			dfs(i);
			if( adj[i].empty()) a ++, mark[i] = true;
			else if( ok ) b ++;
			else c ++;
		}
	}
	ll ans = 0LL;
	//cout << a << " " << b << " " << c << endl;
	ans += a*a, ans += a*(1LL* n - a)*2LL, ans += 2LL*b*b, ans += 2LL*b*c, ans += c*c;
	cout << ans << endl;
	return 0;
}
