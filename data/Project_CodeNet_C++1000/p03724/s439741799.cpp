#include<cstdio>
const int N=1e5+3;
int n,m,deg[N];
signed main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(;m--;)
	  scanf("%d%d",&u,&v),deg[u]++,deg[v]++;
	for(u=1;u<=n;u++)if(deg[u]&1)return 0*puts("NO");
	return 0*puts("YES");
}