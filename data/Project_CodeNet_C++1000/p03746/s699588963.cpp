#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
#define pb push_back
using namespace std;
const int maxn=1e5+10;
int n,m,vis[maxn];vector<int> G[maxn],f;
void dfs(int u){
	for(int v:G[u]) if(!vis[v]){
		vis[v]=1;f.pb(v);
		dfs(v);return;
	}
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m){int u,v;scanf("%d%d",&u,&v),G[u].pb(v),G[v].pb(u);}
	int u=1,v=G[u][0];vis[u]=vis[v]=1;f.pb(u);
	dfs(u);reverse(f.begin(),f.end());f.pb(v);
	dfs(v);printf("%d\n",f.size());
	for(int x:f) printf("%d ",x);
    return 0;
}