#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,tot,ans,head[100010],to[100010],nxt[100010],d[100010];
void add_edge(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
	return;
}
void dfs(int u,int f){
	d[u]=1;
	for(int i=head[u];~i;i=nxt[i]){
		int v=to[i];
		dfs(v,u);
		d[u]=max(d[u],d[v]+1);
	}
	if(d[u]>=k){
		d[u]=0;
		if(f!=1)
			ans++;
	}
	return;
}
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&k,&ans);
	ans=ans!=1;
	for(int i=2;i<=n;i++){
		int v;
		scanf("%d",&v);
		add_edge(v,i);
	}
	for(int i=head[1];~i;i=nxt[i])
		dfs(to[i],1);
	printf("%d",ans);
	return 0;
}