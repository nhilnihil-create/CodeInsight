#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,k,ans,cnt,a[N],dep[N],head[N],to[N*2],nxt[N*2];
void adde(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void dfs(int pre,int u){
	int v;
	for(int i=head[u];i;i=nxt[i]){
		v=to[i];
		if(v!=pre){
			dfs(u,v);
			dep[u]=max(dep[u],dep[v]+1);
		}
	}
	if(dep[u]==k-1&&a[u]!=1){
		ans++;
		dep[u]=-1;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(a[1]!=1){
		ans++;
		a[1]=1;
	}
	for(int i=2;i<=n;i++){
		adde(i,a[i]);
		adde(a[i],i);
	}
	dfs(0,1);
	printf("%d\n",ans);
	return 0;
}