#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005
using namespace std;
typedef long long ll;
struct edge{
	int k,next;
}e[500005];
int n,m,cnt=-1,fa[N<<1],F[N],home[N],col[N],D;
bool vis[N],used[N+N];
void add(int x,int y){
	cnt++;
	e[cnt].k=y;
	e[cnt].next=home[x];
	home[x]=cnt;
}
int find(int k){
	if(fa[k]!=k) fa[k]=find(fa[k]);
	return fa[k];
}
int FIND(int k){
	if(F[k]!=k) F[k]=FIND(F[k]);
	return F[k];
}
void dfs(int k){
	for(int i=home[k];~i;i=e[i].next){
		if(!col[e[i].k]){
			col[e[i].k]=3-col[k];
			dfs(e[i].k);
		}else{
			if(col[e[i].k]==col[k]) D=0;
		}
	}
}
int main(){
	memset(home,-1,sizeof(home));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) F[i]=i;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		vis[x]=vis[y]=1;
		int X=find(x),Y=find(y+n);
		fa[X]=Y;
		X=find(x+n),Y=find(y);
		fa[X]=Y;
		X=FIND(x),Y=FIND(y);
		F[X]=Y;
		add(x,y);add(y,x);
	}
	int tot=0,sum=0;ll ans=0;
	for(int i=1;i<=n;i++) if(!vis[i]) tot++;
	for(int i=1;i<=n;i++) if(!used[find(i)]){
		used[fa[i]]=1;
		sum++;
	}
	int G=0;
	for(int i=1;i<=n;i++) FIND(i),G+=F[i]==i;
	ans=1LL*tot*n;
	for(int i=1;i<=n;i++){
		if(F[i]==i&&vis[i]){
			col[i]=1;D=1;
			dfs(i);
			if(!D) ans+=G;
			else ans+=sum;
		}else if(vis[i]) ans+=tot;
	}
	printf("%lld",ans);
	return 0;
}