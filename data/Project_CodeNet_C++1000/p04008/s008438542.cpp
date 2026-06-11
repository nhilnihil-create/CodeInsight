#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
int dep[MAXN];
int n,k,fa[MAXN],ans;
bool vis[MAXN];
vector<int> a[MAXN];
int dfs(int x,int f){
	vis[x]=1;
	for(int i=0;i<a[x].size();i++){
		int	u=a[x][i];
		dep[x]=max(dep[x],dfs(u,x));
	}
	if((f==0||dep[x]==k-1)&&x!=1&&f!=1){
		ans++;
		return 0;
	}
	dep[x]++;
	return dep[x];
}
int main(){
	SF("%d%d",&n,&k);	
	for(int i=1;i<=n;i++){
		SF("%d",&fa[i]);
		if(i!=1)
			a[fa[i]].push_back(i);
	}
	if(fa[1]!=1){
		ans++;
		fa[1]=1;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==0)
			dfs(i,0);
	PF("%d",ans);
}