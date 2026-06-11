#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define PB push_back
#define INF 1000000001
#define INFL 1000000000000000001
#define M 1000000007
int n,m;
bool vis[100005];
vector<int>g[100005];
vector<int>ans[2];
void dfs(int v,int k){
	vis[v]=true;
	for(int i=0;i<g[v].size();i++){
		if(!vis[g[v][i]]){
			ans[k].PB(g[v][i]);
			dfs(g[v][i],k);
			return;
		}
	}
}
int main(void){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g[--a].PB(--b);
		g[b].PB(a);
	}
	dfs(0,0);
	dfs(0,1);
	printf("%d\n",ans[0].size()+ans[1].size()+1);
	for(int i=ans[0].size();i>0;i--)printf("%d ",ans[0][i-1]+1);
	printf("1");
	for(int i=0;i<ans[1].size();i++)printf(" %d",ans[1][i]+1);
	printf("\n");
}
