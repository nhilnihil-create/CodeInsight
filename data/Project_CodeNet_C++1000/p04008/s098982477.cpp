#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
#define pb push_back
using namespace std;
const int maxn=1e5+10;
int n,K,x,ans,dep[maxn];vector<int> G[maxn];
void dfs(int u,int fa){
	for(int v:G[u]) dfs(v,u),dep[u]=max(dep[u],dep[v]+1);
	if((u^1)&&(fa^1)&&dep[u]==K-1) ++ans,dep[u]=-1;
}
int main(){
	scanf("%d%d",&n,&K);
	rep(i,1,n){
		scanf("%d",&x);
		if(i==1&&x!=1) ++ans;
		if(i^1) G[x].pb(i);
	}
	dfs(1,0);printf("%d\n",ans);
	return 0;
}