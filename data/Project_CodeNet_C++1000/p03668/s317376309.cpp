#include<bits/stdc++.h>
#define N 100009
using namespace std;

int n,tot,fst[N],pnt[N<<1],nxt[N<<1],fa[N];
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
int dfs(int x){
	int i,y,tg=0;
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (y!=fa[x]){
			fa[y]=x; tg^=dfs(y)+1;
		}
	}
	return tg;
}
int main(){
	scanf("%d",&n);
	int i,x,y;
	for (i=1; i<n; i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	puts(dfs(1)?"Alice":"Bob");
	return 0;
}
