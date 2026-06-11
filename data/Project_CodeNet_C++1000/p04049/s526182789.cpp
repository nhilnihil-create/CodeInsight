#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
using namespace std;
const int N=2005;
int n,m,cnt,head[N],d[N],tot,x,y,ans;
struct edge{int to,nxt;}e[N<<1];
void adde(int x,int y){e[++cnt].to=y; e[cnt].nxt=head[x]; head[x]=cnt;}
void dfs(int u,int par){
	for (int i=head[u],v;i;i=e[i].nxt)
		if (v=e[i].to,v!=par) d[v]=d[u]+1,dfs(v,u);
}
int main(){
	scanf("%d%d",&n,&m);
	rep (i,1,n-1) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	ans=n;
	if (m&1){
		rep (i,1,n-1){
			int x=e[2*i].to,y=e[2*i-1].to;
			d[x]=d[y]=0; dfs(x,y); dfs(y,x); tot=0;
			rep (j,1,n) if (d[j]>m/2) tot++;
			ans=min(ans,tot);
		}
	} else{
		rep (x,1,n){
			d[x]=0; dfs(x,0); tot=0;
			rep (j,1,n) if (d[j]>m/2) tot++;
			ans=min(ans,tot);
		}
	}
	printf("%d\n",ans);
	return 0;
}
