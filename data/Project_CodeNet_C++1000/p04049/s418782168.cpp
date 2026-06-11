#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define gc get_char
#define pc putchar 
#define cs const

cs int N=2003;
vector<int> edge[N];
inline void addedge(int u,int v){
	edge[u].push_back(v);
	edge[v].push_back(u);
}

int cnt,ans=0x7fffffff;
int lim;

void dfs(int u,int fa,int dep){
	if(dep>lim/2)++cnt;
	for(int re e=0,v;e<edge[u].size();++e){
		v=edge[u][e];
		if(v^fa)dfs(v,u,dep+1);
	}
}

int n;
signed main(){
	scanf("%d%d",&n,&lim);
	for(int re i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	if(lim&1){
		for(int re u=1;u<=n;++u)
		for(int re e=0;e<edge[u].size();++e){
			cnt=0;dfs(u,edge[u][e],0);
			dfs(edge[u][e],u,0);
			ans=min(ans,cnt);
		}
	}
	else {
		for(int re i=1;i<=n;++i){
			cnt=0;
			dfs(i,0,0);
			ans=min(ans,cnt);
		}
	}
	printf("%d",ans);
	return 0;
}