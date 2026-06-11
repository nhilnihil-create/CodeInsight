#include <iostream>
#include <cstdio>
#include <cmath>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e5+5;
struct edge{
	int v,Next;
}e[N<<2];
int head[N],cnt,n,root,ans=1;
long long a[N],d[N];
void addedge(int u,int v){
	e[++cnt].v=v;
	e[cnt].Next=head[u];
	head[u]=cnt;
}
void dfs(int p,int fa){
	long long Maxn=0,Sum=0;
	for(int ne=head[p];ne;ne=e[ne].Next){
		if(e[ne].v==fa) continue;
		dfs(e[ne].v,p);
		Sum+=a[e[ne].v];
		Maxn=max(Maxn,a[e[ne].v]);
	}
	if(d[p]==1) return ;
	long long x=Sum-a[p],y=2*a[p]-Sum;
	if(x<0||y<0||x>min(Sum-Maxn,Sum/2)||(fa==0&&y)) ans=0;
	a[p]=y;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,2,n){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);addedge(v,u);
		d[u]++;d[v]++;
	}
	rep(i,1,n) if(d[i]>1) root=i;
	if(root) dfs(root,0); else ans=a[1]==a[2];
	if(ans) puts("YES"); else puts("NO");
	return 0;
}
