#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 300000

LL n,x,y,a[N],deg[N],tot,head[N];
struct edge{LL v,nxt;}e[N];

void add(LL x,LL y){e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;}

void dfs(LL u,LL fa){
	if (deg[u]==1) return;
	LL o=0; a[0]=-1;
	LL sum=0;
	for (LL i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa){
			dfs(v,u);
			sum+=a[v];
			if (a[v]>a[o]) o=v;
		}
	if (sum<a[u]||sum>a[u]*2){puts("NO"); exit(0);}
	LL k=a[u]*2-sum;
	if (a[o]-k>sum-a[o]){puts("NO"); exit(0);}
	a[u]=k;
}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i) scanf("%lld",a+i);
	if (n==2){puts(a[1]==a[2]?"YES":"NO"); return 0;}
	for (LL i=1;i<n;++i){
		scanf("%lld%lld",&x,&y);
		add(x,y); add(y,x);
		++deg[x]; ++deg[y];
	}
	for (LL i=1;i<=n;++i)
		if (deg[i]>1){
			dfs(i,0);
			puts(a[i]==0?"YES":"NO");
			return 0;
		}
	
	return 0;
}
			