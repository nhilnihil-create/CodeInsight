#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>g[100005];
vector<int>ans;
int v[100005];
inline void dfs(int x){
	v[x]=1;
	ans.push_back(x);
	for(int i=0;i<g[x].size();i++){
		int k=g[x][i];
		if(v[k]) continue;
		dfs(k);
		return;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	reverse(ans.begin(),ans.end());
	int tmp=ans.size();
	dfs(1);
	printf("%d\n",ans.size()-1);
	for(int i=0;i<ans.size();i++){
		if(ans[i]==1&&i!=tmp-1) continue;
		printf("%d ",ans[i]);
	}
	return 0; 
}