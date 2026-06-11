#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int n,tot,sg[N],head[N];
struct Edge{int u,v,next;}G[N<<1];
inline int read(){
	int f=1,x=0;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return f*x;
}
inline void addedge(int u,int v){
	G[++tot].u=u;G[tot].v=v;G[tot].next=head[u];head[u]=tot;
	G[++tot].u=v;G[tot].v=u;G[tot].next=head[v];head[v]=tot;
}
inline int dfs(int u,int f){
	sg[u]=0;
	for(int i=head[u];i;i=G[i].next){
		int v=G[i].v;if(v==f)continue;
		sg[u]=sg[u]^(dfs(v,u)+1);
	}
	return sg[u];
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		addedge(u,v);
	}
	dfs(1,0);
	if(sg[1])puts("Alice");else puts("Bob");
}