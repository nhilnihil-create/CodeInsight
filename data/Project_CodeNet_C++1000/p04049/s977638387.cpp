
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define f(i,a,b) for (int i = a; i < b; i++)
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin>>n>>k;
	vi adj[n];
	f(i,0,n-1) {
		int a, b; cin >> a >> b;
		adj[--a].pb(--b); adj[b].pb(a);
	}
	function<int(int,int,int)> dfs = [&](int v, int p, int d) {
		int ans = d>k/2;	
		for (int w : adj[v]) if (w != p)
			ans += dfs(w,v,d+1);
		return ans;
	};
	int ans = n;
	if (k&1) {
		f(v,0,n) for (int w : adj[v]) 
			ans = min(ans, dfs(v,w,0)+dfs(w,v,0));
	} else 
		f(v,0,n) ans = min(ans,dfs(v,-1,0));
	cout << ans << endl;
	return 0;
}

