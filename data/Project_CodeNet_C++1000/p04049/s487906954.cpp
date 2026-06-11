#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL ec = 0,nxt[4005],to[4005],hed[2005] = {0};
void add_edge(LL f,LL t){
	++ ec; to[ec] = t; nxt[ec] = hed[f]; hed[f] = ec;
}

LL n,k;
LL siz[2005],dep[2005],del;
void dfs(LL u,LL f){
	dep[u] = dep[f] + 1;
	if(dep[u] > k) del ++;
	for(LL i = hed[u];i;i = nxt[i]){
		LL v = to[i];
		if(v == f) continue;
		dfs(v,u);
	}
}

int main(){
	ios::sync_with_stdio(false);
	LL ans = 0x3f3f3f3f3f3f3f3f;
	LL u[2005],v[2005];
	cin >> n >> k;
	for(LL i = 1;i < n;i ++){
		cin >> u[i] >> v[i];
		add_edge(u[i],v[i]);
		add_edge(v[i],u[i]);
	}
	if(k & 1){
		k >>= 1;
		for(LL i = 1;i < n;i ++){
			del = 0;
			dep[v[i]] = -1; dfs(u[i],v[i]);
			dep[u[i]] = -1; dfs(v[i],u[i]);
			ans = min(ans,del);
		}
	}
	else{
		k >>= 1; dep[0] = -1;
		for(LL i = 1;i <= n;i ++){
			del = 0; dfs(i,0);
			ans = min(ans,del);
		}
	}
	cout << ans << endl;
	return 0;
}
//