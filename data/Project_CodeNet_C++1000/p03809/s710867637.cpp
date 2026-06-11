#include<bits/stdc++.h>
#define N 100009
using namespace std;

int n,cnt,tot,fa[N],f[N],q[N],fst[N],pnt[N<<1],nxt[N<<1],dgr[N],a[N];
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
	dgr[y]++;
}
int dfs(int x){
	int i,y;
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (y!=fa[x]){
			fa[y]=x; dfs(y);
		}
	}
	for (i=fst[x],cnt=0; i; i=nxt[i]){
		y=pnt[i];
		if (y!=fa[x]) q[++cnt]=f[y];
	}
	if (!cnt) return f[x]=a[x];
	sort(q+1,q+cnt+1);
	int tmp=0;
	for (i=1; i<=cnt; i++) tmp+=q[i];
	if (tmp<a[x]){
		puts("NO"); exit(0);
	}
	tmp-=a[x];
	int res=0;
	for (i=1; i<cnt; i++) res+=q[i];
	if (res<tmp){
		puts("NO"); exit(0);
	}
	res+=q[cnt];
	if (res<(tmp<<1)){
		puts("NO"); exit(0);
	}
	return f[x]=a[x]-tmp;
}
int main(){
	scanf("%d",&n);
	int i,x,y;
	for (i=1; i<=n; i++) scanf("%d",&a[i]);
	if (n==2){
		puts(a[1]==a[2]?"YES":"NO"); return 0;
	}
	for (i=1; i<n; i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for (i=1; i<=n; i++) if (dgr[i]>1){
		puts(dfs(i)?"NO":"YES"); break;
	}
	return 0;
}
