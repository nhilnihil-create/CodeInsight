#include <iostream>
#include <cstdlib>
#include <cstdio>
#define N 200011
using namespace std;
struct apple{
	int v,nxt;
}edge[N*4];
int indexx[N],n,dp[N],tot;
void addedge(int x,int y){
	edge[++tot].v=y;
	edge[tot].nxt=indexx[x];
	indexx[x]=tot;
}
void dfs(int u,int fa){
	int t=indexx[u],vv;
	while(t){
		vv=edge[t].v;
		if(vv!=fa){
			dfs(vv,u);
			dp[u]^=(dp[vv]+1);
		}
		t=edge[t].nxt;
	}
}
int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,0);
	if(dp[1]) printf("Alice\n");
	else printf("Bob\n");
	return 0;
}