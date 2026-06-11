#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=100000;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int sg[Maxn+5];
void dfs(int u,int fa){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		dfs(v,u);
		sg[u]^=(sg[v]+1);
	}
}
int main(){
	read(n);
	for(int i=1;i<n;i++){
		int u,v;
		read(u),read(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	if(sg[1]){
		puts("Alice");
	}
	else{
		puts("Bob");
	}
	return 0;
}
