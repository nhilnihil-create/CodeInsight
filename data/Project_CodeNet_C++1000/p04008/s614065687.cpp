#include<cstdio>
#include<algorithm>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
using namespace std;
const int N=1e5+11;
int n,k,tot,ans;
int a[N],nxt[N],las[N],to[N],dis[N];
inline void add(int x,int y){
	nxt[++tot]=las[x];
	las[x]=tot;
	to[tot]=y;
}
inline void dfs(int x){
	dis[x]=1;
	for(register int e=las[x];e;e=nxt[e]){
		dfs(to[e]);
		dis[x]=max(dis[x],dis[to[e]]+1);
	}
	if(dis[x]>=k&&a[x]>1)
		++ans,dis[x]=0;
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)
		scanf("%d",a+i);
	if(a[1]!=1)++ans,a[1]=1;
	rep(i,2,n)
		add(a[i],i);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}