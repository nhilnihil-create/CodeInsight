#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

LL n,m,col[200005] = {0};
vector <LL> G[200005];
LL flg,siz,cnt[3] = {0};
LL ans;

void dfs(LL u,LL f){
	for(LL i = 0;i < G[u].size();i ++){
		LL v = G[u][i];
		if(col[v] && col[v] == col[u]) flg = 1;
		if(!col[v]){
			col[v] = 3 - col[u]; siz ++;
			dfs(v,u);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	LL u,v;
	cin >> n >> m;
	
	for(LL i = 1;i <= m;i ++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(LL i = 1;i <= n;i ++){
		if(col[i]) continue;
		flg = 0; siz = 1; col[i] = 1; dfs(i,0);
		if(siz == 1) cnt[2] ++;
		else cnt[flg] ++;
	}
	ans = (2 * n * cnt[2] - cnt[2] * cnt[2]) + (2 * cnt[0] * cnt[0]) + (cnt[1] * cnt[1] + cnt[1] * cnt[0] * 2);
	cout << ans << endl;
	return 0;
}