#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
int n, m, a[100005], v, u, k, l[2];
vector<int> G[100005];
int dfs(int u, int c){
	a[u] = c;
	int ret = 0;
	for(int nx: G[u]) if(a[nx] != -c){
		if(a[nx] == c) ret = 1;
		else ret |= dfs(nx,-c);
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	rep(i,m){
		scanf("%d%d", &v, &u);
		v--; u--;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	rep(i,n) if(a[i] == 0){
		if(G[i].size() == 0) k++;
		else l[dfs(i,1)]++;
	}
	printf("%lld\n", (ll)k*n*2 - (ll)k*k + (ll)(l[0] + l[1])*(l[0]+l[1]) + (ll)l[0]*l[0]);
}