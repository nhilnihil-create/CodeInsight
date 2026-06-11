#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)

using namespace std;

const int N=1e5+10;
int n,a[N],cnt,head[N],rt,rd[N];
struct edge{int to,nxt;}e[N<<1];

void adde(int x,int y){
	e[++cnt].to=y; e[cnt].nxt=head[x]; head[x]=cnt;
}

void dfs(int u,int par){
	int sum=0,mx=0,leaf=1;
	for (int i=head[u],v;i;i=e[i].nxt)
		if (v=e[i].to,v!=par)
			dfs(v,u),sum+=a[v],mx=max(mx,a[v]),leaf=0;
	if (leaf) return;
	if (a[u]>sum){puts("NO"); exit(0);}
	int t=min(sum-mx,sum>>1);
	if (sum-a[u]>t){puts("NO"); exit(0);}
	a[u]-=sum-a[u];
}

int main(){
	scanf("%d",&n);
	rep (i,1,n) scanf("%d",&a[i]);
	rep (i,1,n-1){int x,y; scanf("%d%d",&x,&y),adde(x,y),adde(y,x),rd[x]++,rd[y]++;}
	if (n==2) return puts(a[1]==a[2]?"YES":"NO"),0;
	rep (i,1,n) if (rd[i]>1){rt=i; break;}
	dfs(rt,0);
	puts(!a[rt]?"YES":"NO");
	return 0;
}