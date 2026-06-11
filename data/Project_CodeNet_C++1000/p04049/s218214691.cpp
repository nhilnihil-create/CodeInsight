#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=2010;
using namespace std;
int n,k,tot,h[N],d[N];
struct Edge{int u,v,nxt;}e[N<<1];
void add(int a,int b){e[++tot]=Edge{a,b,h[a]},h[a]=tot;}
void dfs(int x,int fx){
	for(int i=h[x];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fx) continue;
		d[v]=d[x]+1,dfs(v,x);
	}
}int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,a,b;i<n;i++) scanf("%d%d",&a,&b),add(a,b),add(b,a);
	int ans=1<<30;
	if(k&1){
		for(int i=1;i<=tot;i++){
			d[e[i].u]=d[e[i].v]=0;
			dfs(e[i].u,e[i].v),dfs(e[i].v,e[i].u);
			int tmp=0;
			for(int j=1;j<=n;j++)
				if(d[j]>k/2) ++tmp;
			ans=min(ans,tmp);	
		}
	}else{
		for(int i=1;i<=n;i++){
			d[i]=0,dfs(i,-1);
			int tmp=0;
			for(int j=1;j<=n;j++)
				if(d[j]>k/2) ++tmp;
			ans=min(ans,tmp);	
		}
	}printf("%d\n",ans);	
}