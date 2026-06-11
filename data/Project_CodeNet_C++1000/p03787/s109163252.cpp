#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MAXN = 200005;
const int MOD = 1000000007;

vector<int> g[MAXN];
ll even,odd,isolated,tim;
int vis[MAXN];

int dfs(int a,int f){
	vis[a] = f;
	int ans = 0;
	for(int i:g[a]){
		if(vis[i] && (vis[a] - vis[i]) == 0) ans = 1;
		if(!vis[i]){
			int k = dfs(i,3-f);
			if(k) ans = 1;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin >> n;
	int m; cin >> m;
	for(int i=0;i<m;i++){
		int a,b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(g[i].size() == 0) {
				isolated++; continue;
			}
			int k = dfs(i,1);
			if(k) odd++;
			else even++;
		}
	}
	ll ans = odd * (odd + even) + even * (even * 2 + odd) + (n - isolated) * isolated * 2 + isolated * isolated;
	cout << ans << '\n';
	return 0;
}
