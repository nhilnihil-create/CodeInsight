// by Balloons
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
 
using namespace std;
 
typedef long long LL;
 
const int inf = 1 << 30;
const int maxn=4005;
 
int n,d;
vector<int>g[maxn]; 
int vis[maxn],dis[maxn];
int ex[maxn],ey[maxn];
 
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int u=g[x][i];
		if(vis[u])continue;
		dis[u]=dis[x]+1;
		dfs(u);
	}
}
 
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&ex[i],&ey[i]);
		g[ex[i]].push_back(ey[i]);g[ey[i]].push_back(ex[i]);
	}
	if(d&1){
		int ans=inf;
		for(int i=1;i<=n-1;i++){
			memset(vis,0,sizeof vis);memset(dis,0,sizeof dis);
			int u=ex[i],v=ey[i];
			vis[v]=1;
			dfs(u);
			
			vis[v]=0;
			dfs(v);
			
			int res=0;
			for(int j=1;j<=n;j++)
				if(dis[j]>(d-1)/2)++ res;
				
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}else{
		int ans=inf;
		for(int i=1;i<=n;i++){
			int x=i;
			memset(vis,0,sizeof vis);
			dis[x]=0;
			dfs(x);
//			for(int j=1;j<=n;j++)printf("%d ",dis[j]);puts("");
			
			int res=0;
			for(int j=1;j<=n;j++)
				if(dis[j]>d/2)++ res;
 
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
 
	return 0;
}