#include<bits/stdc++.h>
using namespace std;
vector<int> e[100010];
int cnti,cntb,cntr;
int vis[100010];

bool dfs(int x,int c){
	vis[x]=c;
	bool res = true;
	for(int it:e[x])
		if(vis[it]){
			if(vis[x]+vis[it]!=3)
				res=false;
		}
		else
			res&=dfs(it,3-c);
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)
		cin>>u>>v,e[u].emplace_back(v),e[v].emplace_back(u);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			if(e[i].size()==0)
				cnti++;
			else if(dfs(i,1))
				cntb++;
			else
				cntr++;
		}
	long long int ans = 0;
	ans = 1LL*cnti*cnti+2LL*cnti*(n-cnti)+2LL*cntb*cntb+2LL*cntb*cntr+1LL*cntr*cntr;
	cout<<ans<<endl;
}
