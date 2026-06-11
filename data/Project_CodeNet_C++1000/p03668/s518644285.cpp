#include <cstdio>
const int N=100005;
int fst[N],f[N],tot=0;
struct Edge{
	int to,nxt;
}e[N*2];
void addedge(int x,int y){
	e[++tot].to=y;e[tot].nxt=fst[x];fst[x]=tot;
}
void dfs(int x,int fa){
	for (int i=fst[x];i;i=e[i].nxt){
		int y=e[i].to;
		if (y!=fa){
			dfs(y,x);
			f[x]^=f[y]+1;
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,0);
	if (f[1]) printf("Alice\n");
		else printf("Bob\n");
}