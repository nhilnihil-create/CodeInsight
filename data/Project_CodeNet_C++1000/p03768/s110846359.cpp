#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define re register
#define N 100007
using namespace std;
struct node{
	int u,d;
};
struct edge{
	int to,next;
}e[N<<1];
inline int read(){
    int x=0,w=0;char ch=getchar();
    while (!isdigit(ch))w|=ch=='-',ch=getchar();
    while (isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return w?-x:x;
}
int cnt,head[N],dis[N],vis[N],r[N],s[N],d[N],c[N],col[N],tot,n,m,ttt;
inline void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void dfs(int u,int d,int c){
	if (!d||d<=r[u])return;
	r[u]=d;
	if (!col[u])col[u]=c;
	for (int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		dfs(v,d-1,c);
	}
}
signed main(){
	n=read();m=read();
	for (int i=1;i<=m;++i){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	int Q=read();
	for (int i=1;i<=Q;++i){
		s[i]=read(),d[i]=read(),c[i]=read();
	}
	for (int i=Q;i;--i){
		dfs(s[i],d[i]+1,c[i]);
	}
	for (int i=1;i<=n;++i)printf("%d\n",col[i]);
    return 0;
}
