#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
typedef long long ll;
struct node{
	int x;
	node *nxt;	
}edge[MAXN*4];
node *head[MAXN],*ncnt=edge;
void add_edge(int u,int v){
	++ncnt;
	ncnt->x=v;
	ncnt->nxt=head[u];
	head[u]=ncnt;	
}
int fa[MAXN],n,m,tag[MAXN],dep[MAXN],siz[MAXN],tot;
int get_fa(int x){
	if(fa[x]==0)
		return x;
	fa[x]=get_fa(fa[x]);
	return fa[x];	
}
pair<int,int> l[MAXN*2];
void dfs(int x,int f){
	dep[x]=dep[f]^1;
	for(node *v=head[x];v!=NULL;v=v->nxt){
		int u=v->x;
		if(u==f)
			continue;
		dfs(u,x);
	}
}
ll cnt[2];
int main(){
	int u,v;
	SF("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		siz[i]=1;
	for(int i=1;i<=m;i++){
		SF("%d%d",&u,&v);
		if(get_fa(u)!=get_fa(v)){	
			add_edge(u,v);
			add_edge(v,u);
			u=get_fa(u);
			v=get_fa(v);
			fa[u]=v;
			siz[v]+=siz[u];
		}
		else
			l[++tot]=make_pair(u,v);
	}
	for(int i=1;i<=n;i++)
		if(fa[i]==0)
			dfs(i,0);
	for(int i=1;i<=tot;i++)
		if(dep[l[i].first]==dep[l[i].second])
			tag[get_fa(l[i].first)]=1;	
	ll ans=0,poi=0;
	for(int i=1;i<=n;i++)
		if(fa[i]==0){
			if(siz[i]==1){
				ans+=n;
				poi++;
			}
			else
				cnt[tag[i]]++;
		}
	ans+=(n-poi)*poi;
	ans+=cnt[1]*(cnt[1]+cnt[0]*2ll);
	ans+=cnt[0]*cnt[0]*2ll;
	PF("%lld",ans);
		
}