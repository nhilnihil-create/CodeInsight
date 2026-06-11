#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge{
	int t,next;
}g[400001];
ll ans,t1,t2,t3;
int tmp,c[200001],i,j,k,n,m,tot,h[200001],flag;
void addedge(int x,int y){
	g[++tot].t=y;g[tot].next=h[x];h[x]=tot;
	g[++tot].t=x;g[tot].next=h[y];h[y]=tot;
}
void dfs(int x){
	int i;
	tmp++;
	for (i=h[x];i;i=g[i].next)
	 if (!c[g[i].t]) c[g[i].t]=3-c[x],dfs(g[i].t);
	 else if (c[g[i].t]==c[x]) flag=0;
}
int main(){
	//freopen("data.in","r",stdin);freopen("data1.out","w",stdout);
//	while (1){
		scanf("%d%d",&n,&m);
	//	if (!n) break;
		memset(h,0,sizeof(h));memset(c,0,sizeof(c));tot=0;
		for (i=1;i<=m;i++) scanf("%d%d",&j,&k),addedge(j,k);
		for (i=1,t1=t2=t3=0;i<=n;i++)
		 if (!c[i]){
		 	c[i]=flag=1;tmp=0;dfs(i);
		 	if (tmp==1) t3++;
		 	else if (flag) t2++;else t1++;
		 }
		//ans=t1*t1+2LL*t1*t2+2LL*t2*t2;
	//	ans+=(ll)n*(ll)n-(ll)(n-t3)*(ll)(n-t3);
		ans=2*t3*(ll)n-t3*t3+t1*t1+2LL*t1*t2+2LL*t2*t2;
		printf("%lld\n",ans);
//	}
	return 0;
}
