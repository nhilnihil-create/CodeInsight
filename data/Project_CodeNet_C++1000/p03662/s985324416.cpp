#include <stdio.h>
#include <string.h>
#define MN 100000
#define MM 200000
int n,a,b,c1=0,c2=0;
int p[MN+5],pn=0,col[MN+5];
int hd[MN+5],nxt[MM+5],to[MM+5],rn=0;
void add(int u,int v){
	++rn;
	nxt[rn]=hd[u];
	hd[u]=rn;
	to[rn]=v;
}
bool dfs(int u){
	p[++pn]=u;
	if(u==n) return true;
	for(int i=hd[u];i!=-1;i=nxt[i])
		if(p[pn-1]!=to[i])
			if(dfs(to[i]))
				return true;
	--pn;
	return false;
}
void spr(int u){
	for(int i=hd[u];i!=-1;i=nxt[i])
		if(col[to[i]]==0){
			col[to[i]]=col[u];
			spr(to[i]);
		}
}
int main(){
	memset(hd,0xff,sizeof(hd));
	memset(col,0,sizeof(col));
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	dfs(1);
	for(int i=1;i<=pn;i++)
		if(i<=((pn+1)>>1)) col[p[i]]=1;
		else col[p[i]]=2;
	for(int i=1;i<=pn;i++) spr(p[i]);
	for(int i=1;i<=n;i++){
		if(col[i]==0) return 1;
		if(col[i]==1) c1++;
		if(col[i]==2) c2++;
	}
	if(c1<=c2) puts("Snuke");
	else puts("Fennec");
}