#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
vector<int> G[maxn];
int col[maxn];
void dfs1(int u,int color) {
	col[u] = color;
	for(int v : G[u])
		if(col[v] == 0)
			dfs1(v,color);
}
int ans[maxn];
void dfs2(int u,vector<int> &idxs) {
	ans[u] = -1;	// visited
	idxs.emplace_back(u);
	for(int v : G[u])
		if(ans[v] == 0)
			dfs2(v,idxs);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k,l;
	cin >> n >> k >> l;
	for(int i=1,u,v;i<=k;i++) {
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	int tmp = 1;
	for(int i=1;i<=n;i++)
		if(col[i] == 0)
			dfs1(i,tmp) , tmp++;
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1,u,v;i<=l;i++) {
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	for(int i=1;i<=n;i++)
		if(ans[i] == 0) {
			vector<int> idxs;
			dfs2(i,idxs);
			
			sort(idxs.begin(),idxs.end(),[=](int a,int b)->bool
				{return col[a] < col[b];});
			for(int j=0;j<(int)idxs.size();) {
				int r = upper_bound(idxs.begin(),idxs.end(),idxs[j],[=](int a,int b)->bool
					{return col[a] < col[b];})-idxs.begin()-1;
				int num = r - j + 1;
				for(;j<=r;j++)
					ans[idxs[j]] = num;
			}
		}
	for(int i=1;i<=n;i++) {
		if(i != 1)	cout << " ";
		cout << ans[i];
	}	
	cout << '\n';
	return 0;
}
